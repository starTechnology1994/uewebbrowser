// Copyright (c) 2026 StarTechnology. All rights reserved.

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#if PLATFORM_LINUX
#include "IVulkanDynamicRHI.h"
#include <dlfcn.h>
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Runtime/Launch/Resources/Version.h"
#endif

class FWebNativeBrowserVulkanBootstrapModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
#if PLATFORM_LINUX
		// ── Vulkan Loader Compatibility (UE5.1-5.5) ──────────────────────
		// UE5.6+ bundles its own libvulkan.so in
		// Engine/Binaries/ThirdParty/Vulkan/Linux/ with version detection
		// and automatic fallback (confirmed in engine source:
		// VulkanLinuxPlatform.cpp LoadVulkanLibrary, unconditional path
		// starts at 5.6, see GetVulkanInstanceVersion +
		// dlopen("Binaries/.../libvulkan.so")).
		// UE5.1-5.5 do NOT bundle one (UELayerPath is only set inside
		// #if VULKAN_HAS_DEBUGGING_ENABLED, i.e. Debug-only validation
		// layer path, not a loader fallback).
		// On those versions the system may ship a loader that is too new
		// (e.g. Vulkan-Loader 1.3.275 rejects ICD drivers built for
		// interface version 4, such as the gf/lisuan driver on domestic
		// Linux distributions).
		//
		// Preload our bundled compatible loader BEFORE Vulkan RHI creates
		// its first VkInstance.  Because the loader is a singleton, a
		// subsequent dlopen("libvulkan.so.1") will resolve to our copy.
		// UE5.6+ skip this step → the engine's own loader fallback is
		// sufficient and injecting ours would cause symbol conflicts.
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION <= 5
		{
			// Probe whether the system has a working Vulkan loader.
			// Use RTLD_LOCAL to avoid polluting the global symbol
			// namespace — VulkanRHI will open its own handle later.
			void* ProbeHandle = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
			if (ProbeHandle)
			{
				// The handle succeeded, but it might be our bundled
				// GLIBC-2.17 loader (picked up via linker RUNPATH on
				// older package layouts, or via LD_LIBRARY_PATH).
				// Verify that the loaded library has WSI support
				// (x86_64 bundled: full WSI X11/XCB; arm64: headless).
				bool bHasWSI = (dlsym(ProbeHandle, "vkCreateXlibSurfaceKHR") != nullptr);
				dlclose(ProbeHandle);

				if (bHasWSI)
				{
					UE_LOG(LogTemp, Display,
						TEXT("WebNativeBrowser: system libvulkan.so.1 found with WSI support, using system loader (UE 5.%d)."),
						ENGINE_MINOR_VERSION);
				}
				else
				{
					// Handle loaded but has no WSI symbols → it is our
					// bundled fallback (e.g. arm64 headless build) being
					// picked up instead of the system loader.
					// Force the system path via LD_PRELOAD so VulkanRHI
					// uses the real system loader instead.
					UE_LOG(LogTemp, Error,
						TEXT("WebNativeBrowser: loaded libvulkan.so.1 lacks WSI symbols (bundled headless fallback detected)! ")
						TEXT("The system may lack GPU drivers. Attempting LD_PRELOAD of system Vulkan loader path. ")
						TEXT("If this fails, install GPU drivers: 'apt install libvulkan1 mesa-vulkan-drivers' (Debian/Ubuntu) ")
						TEXT("or 'dnf install vulkan-loader mesa-vulkan-drivers' (RHEL/Fedora)."));
					FPlatformMisc::SetEnvironmentVar(
						TEXT("LD_PRELOAD"),
						TEXT("/usr/lib/x86_64-linux-gnu/libvulkan.so.1"));
				}
			}
			else
			{
				// ── No system Vulkan loader detected ─────────────────
				// This system is likely a headless server or a minimal
				// desktop install without GPU drivers.
				// Fall back to our bundled GLIBC-2.17-compatible copy
				// (x86_64: full WSI X11/XCB support; arm64: headless).
				//
				// IMPORTANT: Even with our fallback loader, UE cannot
				// render without a Vulkan-capable GPU driver + ICD.
				// Users MUST install their GPU vendor's Vulkan driver
				// package (e.g. mesa-vulkan-drivers, nvidia-utils,
				// amdgpu-pro-vulkan) which will provide the system
				// libvulkan.so.1 with full WSI support.
				//
				// NOTE: the loader is staged to Binaries/ThirdParty/VulkanLoader
				// (NOT under Binaries/ThirdParty/CEF) so it does NOT get
				// picked up by the linker RUNPATH automatically.
				UE_LOG(LogTemp, Error,
					TEXT("WebNativeBrowser: SYSTEM VULKAN LOADER NOT FOUND! This system does not have libvulkan.so.1 installed. ")
					TEXT("We will use our bundled fallback loader (GLIBC 2.17) as a temporary workaround, ")
					TEXT("but Vulkan rendering will still fail without a GPU driver and ICD (Installable Client Driver). ")
					TEXT("Please install the Vulkan loader package for your distribution: ")
					TEXT("'apt install libvulkan1 mesa-vulkan-drivers' (Debian/Ubuntu) or ")
					TEXT("'dnf install vulkan-loader mesa-vulkan-drivers' (RHEL/Fedora) or ")
					TEXT("the equivalent package for your Linux distribution."));

				TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("WebNativeBrowser"));
				if (Plugin.IsValid())
				{
					FString LoaderDir = FPaths::Combine(
						Plugin->GetBaseDir(),
#if PLATFORM_CPU_ARM_FAMILY
						TEXT("Binaries/ThirdParty/VulkanLoader/Linux/arm64"));
#else
						TEXT("Binaries/ThirdParty/VulkanLoader/Linux/x86_64"));
#endif
					if (FPaths::DirectoryExists(LoaderDir))
					{
						FString OldPath = FPlatformMisc::GetEnvironmentVariable(TEXT("LD_LIBRARY_PATH"));
						FString NewPath = LoaderDir;
						if (!OldPath.IsEmpty())
						{
							NewPath = OldPath + TEXT(":") + NewPath;
						}
						FPlatformMisc::SetEnvironmentVar(TEXT("LD_LIBRARY_PATH"), *NewPath);
						UE_LOG(LogTemp, Display,
							TEXT("WebNativeBrowser: added bundled fallback libvulkan.so.1 to LD_LIBRARY_PATH (%s)."),
							*LoaderDir);
					}
					else
					{
						UE_LOG(LogTemp, Error,
							TEXT("WebNativeBrowser: bundled Vulkan loader directory not found at %s! Vulkan will not initialize."),
							*LoaderDir);
					}
				}
			}
		}
#endif // UE5.1-5.5

		// ── Vulkan DMA-BUF Extensions ────────────────────────────────────
		// UE 5.1-5.7 keep external_memory_fd manually disabled. Request
		// both DMA-BUF dependencies before Vulkan creates the logical
		// device. UE 5.8 safely de-duplicates extensions it already
		// enables itself.
		const ANSICHAR* DeviceExtensions[] =
		{
			VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME,
			VK_EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME,
		};
		IVulkanDynamicRHI::AddEnabledDeviceExtensionsAndLayers(
			MakeArrayView(DeviceExtensions),
			TArrayView<const ANSICHAR* const>());
		UE_LOG(LogTemp, Display,
			TEXT("WebNativeBrowser: requested Vulkan DMA-BUF device extensions before RHI startup."));
#endif
	}
};

IMPLEMENT_MODULE(FWebNativeBrowserVulkanBootstrapModule, WebNativeBrowserVulkanBootstrap)
