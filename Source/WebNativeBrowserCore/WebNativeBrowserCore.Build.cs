// Copyright (c) 2026 StarTechnology. All rights reserved.

using System;
using System.IO;
using UnrealBuildTool;

public class WebNativeBrowserCore : ModuleRules
{
	private static bool ProtectedFilesMatch(string Source, string Destination)
	{
		if (!File.Exists(Destination))
		{
			return false;
		}

		FileInfo SourceInfo = new FileInfo(Source);
		FileInfo DestinationInfo = new FileInfo(Destination);
		return SourceInfo.Length == DestinationInfo.Length;
	}

	private static void RestoreProtectedFile(string Source, string Destination)
	{
		string DestinationDirectory = Path.GetDirectoryName(Destination);
		if (!Directory.Exists(DestinationDirectory))
		{
			Directory.CreateDirectory(DestinationDirectory);
		}

		for (int Attempt = 0; Attempt < 3; ++Attempt)
		{
			if (ProtectedFilesMatch(Source, Destination))
			{
				return;
			}

			string Temporary = Destination + ".wnbrestore." +
				System.Diagnostics.Process.GetCurrentProcess().Id + "." +
				Guid.NewGuid().ToString("N");
			try
			{
				File.Copy(Source, Temporary, false);
				try
				{
					File.Move(Temporary, Destination);
				}
				catch (IOException)
				{
					if (!ProtectedFilesMatch(Source, Destination))
					{
						File.Copy(Source, Destination, true);
					}
				}

				if (ProtectedFilesMatch(Source, Destination))
				{
					return;
				}
			}
			finally
			{
				if (File.Exists(Temporary))
				{
					try
					{
						File.Delete(Temporary);
					}
					catch
					{
						// A concurrent UBT process may still be completing the same restore.
					}
				}
			}

			System.Threading.Thread.Sleep(20 * (Attempt + 1));
		}

		throw new BuildException(
			"WebNativeBrowser could not restore protected precompiled artifact '{0}'.",
			Destination);
	}

	private void UseProtectedPrecompiledArtifacts()
	{
		string PayloadRoot = Path.Combine(
			PluginDirectory,
			"Resources",
			"WebNativePrecompiled",
			"Payload");
		if (!Directory.Exists(PayloadRoot))
		{
			return;
		}

		// Project-plugin Rebuild cleans Plugin/Binaries and Plugin/Intermediate.
		// The immutable mirror under Resources survives Clean and is restored while
		// UBT is evaluating module rules, before it resolves precompiled manifests
		// and import libraries.
		bUsePrecompiled = true;

		int RestoredFiles = 0;
		foreach (string Source in Directory.EnumerateFiles(
			PayloadRoot,
			"*",
			SearchOption.AllDirectories))
		{
			string RelativePath = Source.Substring(PayloadRoot.Length).TrimStart(
				Path.DirectorySeparatorChar,
				Path.AltDirectorySeparatorChar);
			if (String.IsNullOrEmpty(RelativePath))
			{
				continue;
			}

			string Destination = Path.Combine(PluginDirectory, RelativePath);
			if (!ProtectedFilesMatch(Source, Destination))
			{
				RestoreProtectedFile(Source, Destination);
				++RestoredFiles;
			}
		}

		if (RestoredFiles > 0)
		{
			System.Console.WriteLine(
				"WebNativeBrowser: restored {0} protected precompiled artifact(s) after Clean.",
				RestoredFiles);
		}
	}

	public WebNativeBrowserCore(ReadOnlyTargetRules Target) : base(Target)
	{
		UseProtectedPrecompiledArtifacts();
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// UE PCH includes Windows.h (via MinWindows.h), which pulls in winsock.h (not winsock2.h).
		// _WINSOCKAPI_ prevents winsock.h from being included, so we can include winsock2.h in our .cpp files.
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PrivateDefinitions.Add("_WINSOCKAPI_");
		}

		// UE5.1-5.7 + Unity Build + VS2022: winbase.h (from Windows SDK) declares
		// _InterlockedIncrement / _InterlockedDecrement / _InterlockedExchange
		// as inline functions that collide with MSVC compiler intrinsics.
		// Disabling unity builds forces per-file PCH ordering, which ensures
		// MinWindows.h is processed before Windows.h, avoiding the conflict.
		// UE5.8 的 Windows 平台头已修复该冲突，可保持默认 Unity 构建。
		if (Target.Version.MajorVersion == 5 && Target.Version.MinorVersion <= 7)
		{
			bUseUnity = false;
		}

		// UE5.4+ moved FBlueprintExceptionInfo / EBlueprintExceptionType into
		// their own header (Blueprint/BlueprintExceptionInfo.h); Script.h only
		// forward-declares them. Engine version macros (ENGINE_MAJOR_VERSION)
		// are not defined for precompiled UnrealGame builds, so define a custom
		// macro via Target.Version (reliable in UBT) instead.
		if (Target.Version.MajorVersion == 5 && Target.Version.MinorVersion >= 4)
		{
			PublicDefinitions.Add("WNW_ENGINE_GTE_5_4=1");
		}

		// UE 5.1-5.4 natively default to C++17; forcing C++20 there breaks
		// d3dx12.h. UE 5.5+ uses C++20, and UE 5.8 removes explicit C++17
		// support, so only override the standard on newer engine versions.
		if (Target.Version.MajorVersion > 5 ||
			(Target.Version.MajorVersion == 5 && Target.Version.MinorVersion >= 5))
		{
			CppStandard = CppStandardVersion.Cpp20;
		}

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"Slate",
			"SlateCore",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"ApplicationCore",
			"HTTP",
			"Json",
			"JsonUtilities",
			"Projects",
			"RenderCore",
			"RHI",
			"RSA"
		});

		// Plugin-owned Runtime Slate dialog. Unlike UE's Developer-only
		// SlateFileDialogs module this is available in installed-engine Shipping
		// builds and has no DirectoryWatcher/precompiled-manifest dependency.
		bool bUsesWebNativeFileDialog =
			Target.Platform == UnrealTargetPlatform.Linux ||
			Target.Platform == UnrealTargetPlatform.LinuxArm64;
		if (bUsesWebNativeFileDialog)
		{
			PrivateDependencyModuleNames.Add("WebNativeBrowserFileDialog");
			PublicDefinitions.Add("WITH_WEBNATIVE_FILE_DIALOG=1");
		}
		else
		{
			PublicDefinitions.Add("WITH_WEBNATIVE_FILE_DIALOG=0");
		}

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string CefRoot = Path.Combine(ModuleDirectory, "..", "ThirdParty", "CEF", "Win64");
			string CefRuntime = Path.Combine(PluginDirectory, "Binaries", "ThirdParty", "CEF", "Win64");
			string ProjectRoot = Target.ProjectFile != null
				? Target.ProjectFile.Directory.FullName
				: Path.GetFullPath(Path.Combine(PluginDirectory, "..", ".."));
			string ProjectHelper = Path.Combine(ProjectRoot, "Binaries", "Win64", "WebNativeBrowserHelper.exe");
			string RuntimeHelper = Path.Combine(CefRuntime, "WebNativeBrowserHelper.exe");

			PrivateDependencyModuleNames.AddRange(new[]
			{
				"D3D11RHI",
				"D3D12RHI"
			});

			// UE 5.1-5.4: D3D12RHI's public header ID3D12DynamicRHI.h includes
			// WindowsD3D12ThirdParty.h which includes d3dx12.h. That header is a
			// private dependency of D3D12RHI and not exported to dependent modules.
			// Even if we add the include path, d3dx12.h has MSVC conformance bugs.
			// We provide an empty stub d3dx12.h in our own Source directory to
			// shadow it. Our code only uses raw d3d12.h types, never CD3DX12_*.
			PublicDefinitions.Add("WITH_WN=1");
		PublicDefinitions.Add("CEF_USE_BOOTSTRAP=1");
			PublicSystemIncludePaths.Add(CefRoot);
			PublicSystemIncludePaths.Add(Path.Combine(CefRoot, "include"));
			PublicAdditionalLibraries.Add(Path.Combine(CefRoot, "lib", "libcef_wn.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(CefRoot, "lib", "libcef_dll_wrapper.lib"));
			PublicSystemLibraries.AddRange(new[] { "d3d11.lib", "dxgi.lib" });
			PublicDelayLoadDLLs.Add("libcef_wn.dll");

		// Stage CEF runtime files from Source/ThirdParty/CEF/Win64/
			// to Binaries/ThirdParty/CEF/Win64/ (same pattern as Linux).
			// Using Source/ as the staging source avoids FilePatternException
			// (source != dest), which would occur if we used Binaries/ as source.
			// Skip libcef.lib, debug.log, bootstrap.exe, bootstrapc.exe —
			// none of these are needed at runtime.
			string CefStageSource = CefRoot;
			if (Directory.Exists(CefStageSource))
			{
				// Top-level runtime files (DLLs, dat, bin, pak, json, exe)
				string[] StageTopFiles = new[]
				{
					"WebNativeBrowserHelper.exe",
					"libcef_wn.dll",
					"chrome_elf.dll",
					"d3dcompiler_47.dll",
					"dxcompiler.dll",
					"dxil.dll",
					"libEGL.dll",
					"libGLESv2.dll",
					"vulkan-1.dll",
					"vk_swiftshader.dll",
					"vk_swiftshader_icd.json",
					"chrome_100_percent.pak",
					"chrome_200_percent.pak",
					"resources.pak",
					"icudtl.dat",
					"snapshot_blob.bin",
					"v8_context_snapshot.bin",
				};

				foreach (string FileName in StageTopFiles)
				{
					string SourcePath = Path.Combine(CefStageSource, FileName);
					if (File.Exists(SourcePath))
					{
						string DestPath = Path.Combine("$(PluginDir)/Binaries/ThirdParty/CEF", "Win64", FileName);
						RuntimeDependencies.Add(DestPath, SourcePath, StagedFileType.NonUFS);
					}
				}

				// Locales directory (language packs)
				string LocalesDir = Path.Combine(CefStageSource, "locales");
				if (Directory.Exists(LocalesDir))
				{
					foreach (string LocaleFile in Directory.EnumerateFiles(LocalesDir, "*.pak"))
					{
						string LocaleFileName = Path.GetFileName(LocaleFile);
						string DestPath = Path.Combine("$(PluginDir)/Binaries/ThirdParty/CEF", "Win64", "locales", LocaleFileName);
						RuntimeDependencies.Add(DestPath, LocaleFile, StagedFileType.NonUFS);
					}
				}
			}

			if (File.Exists(ProjectHelper))
			{
				RuntimeDependencies.Add(
					"$(PluginDir)/Binaries/ThirdParty/CEF/Win64/WebNativeBrowserHelper.exe",
					ProjectHelper,
					StagedFileType.NonUFS);
			}
			else if (File.Exists(RuntimeHelper))
			{
				RuntimeDependencies.Add(RuntimeHelper);
			}
			else
			{
				System.Console.WriteLine("WARNING: WebNativeBrowserHelper.exe not found. CEF subprocess will not be included in packaged builds.");
			}
		}
		else if (Target.Platform == UnrealTargetPlatform.Linux || Target.Platform == UnrealTargetPlatform.LinuxArm64)
		{
			// VulkanRHI does not propagate Vulkan ThirdParty include paths to
			// dependent modules when cross-compiling for Linux (all UE5 versions).
			// Add them explicitly.
			// Include/vulkan/ is needed for #include <vulkan.h> in IVulkanDynamicRHI.h.
			// Include/ is needed for #include "vk_video/..." in vulkan_core.h.
			string VulkanIncludeBase = Path.Combine(EngineDirectory, "Source", "ThirdParty", "Vulkan", "Include");
			string VulkanIncludeVulkan = Path.Combine(VulkanIncludeBase, "vulkan");
			if (Directory.Exists(VulkanIncludeVulkan))
			{
				PublicSystemIncludePaths.Add(VulkanIncludeVulkan);
			}
			if (Directory.Exists(VulkanIncludeBase))
			{
				PublicSystemIncludePaths.Add(VulkanIncludeBase);
			}

			// Architecture detection: UnrealArch.bIsArm64 (UE5.1-5.7) vs
			// UnrealArch.bIsX64 (UE5.8). Use ToString() string matching for
			// compatibility across UE5.1-5.8.
			string ArchStr = Target.Architecture.ToString().ToLowerInvariant();
			string CefArch = ArchStr.Contains("arm") || ArchStr.Contains("aarch")
				? "Linux/arm64" : "Linux/x86_64";
			string CefRoot = Path.Combine(ModuleDirectory, "..", "ThirdParty", "CEF", CefArch);
			string CefRuntime = Path.Combine(PluginDirectory, "Binaries", "ThirdParty", "CEF", CefArch);
			// Fallback: if arch-specific runtime dir doesn't exist, try non-arch dir.
			// Allows gradual migration: put files under Linux/x86_64 or Linux/arm64.
			string CefRuntimeFallback = Path.Combine(PluginDirectory, "Binaries", "ThirdParty", "CEF", "Linux");
			string ProjectRoot = Target.ProjectFile != null
				? Target.ProjectFile.Directory.FullName
				: Path.GetFullPath(Path.Combine(PluginDirectory, "..", ".."));
			string ProjectHelper = Target.Platform == UnrealTargetPlatform.LinuxArm64
				? Path.Combine(ProjectRoot, "Binaries", "LinuxArm64", "WebNativeBrowserHelper")
				: Path.Combine(ProjectRoot, "Binaries", "Linux", "WebNativeBrowserHelper");

			PublicDefinitions.Add("WITH_WN=1");
			PublicSystemIncludePaths.Add(CefRoot);
			PublicSystemIncludePaths.Add(Path.Combine(CefRoot, "include"));

			PrivateDependencyModuleNames.AddRange(new[]
			{
				"VulkanRHI"
			});

			// libcef_dll_wrapper static library (compiled separately for Linux).
			// Link this BEFORE libcef_wn.so because it references symbols from libcef_wn.so.
			string LibCefDllWrapperIndexed = Path.Combine(CefRoot, "lib", "libcef_dll_wrapper_indexed.a");
			string LibCefDllWrapper = Path.Combine(CefRoot, "lib", "libcef_dll_wrapper.a");
			if (File.Exists(LibCefDllWrapper))
			{
				PublicAdditionalLibraries.Add(LibCefDllWrapper);
			}
			else if (File.Exists(LibCefDllWrapperIndexed))
			{
				PublicAdditionalLibraries.Add(LibCefDllWrapperIndexed);
			}

			// Link against libcef_wn.so for C API symbols (must come AFTER
			// libcef_dll_wrapper). We must link from the Binaries directory so
			// the linker embeds a Binaries/... RUNPATH into the ELF — the
			// Source directory does not exist in a packaged build and would
			// cause "cannot open shared object file: libcef_wn.so" at startup.
			// On a clean build the Binaries copy may not exist yet, so we copy
			// it from Source first (same as the staging step does later).
			string LibCefSo = Path.Combine(CefRuntime, "libcef_wn.so");
			if (!File.Exists(LibCefSo))
			{
				string SourceCefSo = Path.Combine(CefRoot, "libcef_wn.so");
				if (File.Exists(SourceCefSo))
				{
					Directory.CreateDirectory(CefRuntime);
					File.Copy(SourceCefSo, LibCefSo, true);
					System.Console.WriteLine("WebNativeBrowser: staged libcef_wn.so from Source to Binaries for linking.");
				}
			}
			if (!File.Exists(LibCefSo))
			{
				LibCefSo = Path.Combine(CefRuntimeFallback, "libcef_wn.so");
			}
			if (!File.Exists(LibCefSo))
			{
				LibCefSo = Path.Combine(CefRoot, "libcef_wn.so");
			}
			if (File.Exists(LibCefSo))
			{
				PublicAdditionalLibraries.Add(LibCefSo);
			}
			else
			{
				System.Console.WriteLine("ERROR: libcef_wn.so not found at {0}, {1}, or {2}. CEF C API symbols will be undefined.",
					Path.Combine(CefRuntime, "libcef_wn.so"),
					Path.Combine(CefRuntimeFallback, "libcef_wn.so"),
					Path.Combine(CefRoot, "libcef_wn.so"));
			}

			// Stage CEF runtime files from Source/ThirdParty/CEF/Linux/{arch}/
			// to the packaged output at Binaries/ThirdParty/CEF/Linux/{arch}/.
			// Using Source/ as the staging source avoids FilePatternException
			// (source != dest), which would occur if we used Binaries/ as source.
			string CefStageSource = CefRoot;
			if (Directory.Exists(CefStageSource))
			{
				string[] StageTopFiles = new[]
			{
				"WebNativeBrowserHelper",
				"libcef_wn.so",
				"libEGL.so",
				"libGLESv2.so",
				"libvk_swiftshader.so",
				"vk_swiftshader_icd.json",
				"chrome_100_percent.pak",
				"chrome_200_percent.pak",
				"headless_command_resources.pak",
				"resources.pak",
				"icudtl.dat",
				"snapshot_blob.bin",
				"v8_context_snapshot.bin",
				"chrome_crashpad_handler",
				"chrome_sandbox",
			};

			foreach (string FileName in StageTopFiles)
			{
				string SourcePath = Path.Combine(CefStageSource, FileName);
				if (File.Exists(SourcePath))
				{
					string DestPath = Path.Combine("$(PluginDir)/Binaries/ThirdParty/CEF", CefArch, FileName);
					RuntimeDependencies.Add(DestPath, SourcePath, StagedFileType.NonUFS);
					}
				}

				// Locales directory (language packs)
				string LocalesDir = Path.Combine(CefStageSource, "locales");
				if (Directory.Exists(LocalesDir))
				{
					foreach (string LocaleFile in Directory.EnumerateFiles(LocalesDir, "*.pak"))
					{
						string LocaleFileName = Path.GetFileName(LocaleFile);
						string DestPath = Path.Combine("$(PluginDir)/Binaries/ThirdParty/CEF", CefArch, "locales", LocaleFileName);
						RuntimeDependencies.Add(DestPath, LocaleFile, StagedFileType.NonUFS);
					}
				}
			}

			// Stage our bundled libvulkan.so.1 to a SEPARATE directory OUTSIDE
			// the CEF RPATH (Binaries/ThirdParty/CEF is in the linker's RUNPATH,
			// which takes priority over system paths and would shadow the system
			// loader on distributions that already ship one).
			// VulkanBootstrap.cpp will add this directory to LD_LIBRARY_PATH at
			// runtime ONLY when the system has no working loader.
			{
				string VulkanSource = Path.Combine(CefStageSource, "libvulkan.so.1");
				if (File.Exists(VulkanSource))
				{
					string VulkanDest = Path.Combine("$(PluginDir)/Binaries/ThirdParty/VulkanLoader", CefArch, "libvulkan.so.1");
					RuntimeDependencies.Add(VulkanDest, VulkanSource, StagedFileType.NonUFS);
				}
			}

			// Stage the CEF subprocess helper from Source (avoiding source==dest).
			// Priority: Source/ThirdParty > Binaries/ThirdParty > non-arch fallback > project.
			string HelperCandidate = Path.Combine(CefRoot, "WebNativeBrowserHelper");
			if (!File.Exists(HelperCandidate))
			{
				HelperCandidate = Path.Combine(CefRuntime, "WebNativeBrowserHelper");
			}
			if (!File.Exists(HelperCandidate))
			{
				HelperCandidate = Path.Combine(CefRuntimeFallback, "WebNativeBrowserHelper");
			}
			if (!File.Exists(HelperCandidate))
			{
				HelperCandidate = ProjectHelper;
			}
			if (File.Exists(HelperCandidate))
			{
				string HelperDest = Path.Combine("$(PluginDir)/Binaries/ThirdParty/CEF", CefArch, "WebNativeBrowserHelper");
				RuntimeDependencies.Add(HelperDest, HelperCandidate, StagedFileType.NonUFS);
			}
			else
			{
				System.Console.WriteLine("WARNING: WebNativeBrowserHelper (Linux) not found. CEF subprocess will not be included in packaged builds.");
			}
		}
		else
		{
			PublicDefinitions.Add("WITH_WN=0");
		}

		// Stage local HTML as physical files in the packaged plugin Content directory.
		// CEF loads these pages through file://, so they must remain NonUFS. Do not
		// specify a separate source path: this marks the existing plugin Content file
		// for staging without first copying it into the project root.
		if (Target.Type != TargetType.Editor)
		{
			string HtmlSourceDir = Path.Combine(PluginDirectory, "Content", "webnative", "html");
			if (Directory.Exists(HtmlSourceDir))
			{
				// Stage all files recursively (HTML + assets/ subdirectory with JS libs, images, etc.)
				// Use the 2-parameter overload (path only) because these files already live in the
				// plugin Content directory — specifying a source path would trigger "listed as a
				// source and target file" since source == dest.
				foreach (string FilePath in Directory.EnumerateFiles(HtmlSourceDir, "*", SearchOption.AllDirectories))
				{
					string RelativePath = FilePath.Substring(HtmlSourceDir.Length).TrimStart(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar);
					// Normalize to forward slashes for the destination path
					RelativePath = RelativePath.Replace('\\', '/');
					RuntimeDependencies.Add(
						Path.Combine("$(PluginDir)", "Content", "webnative", "html", RelativePath),
						StagedFileType.NonUFS);
				}
			}

			// License files are read directly from plugin Content at runtime too.
			string LicenseSourceDir = Path.Combine(PluginDirectory, "Content", "webnative", "licenses");
			if (Directory.Exists(LicenseSourceDir))
			{
				foreach (string LicenseFile in Directory.EnumerateFiles(LicenseSourceDir, "*.license"))
				{
					string FileName = Path.GetFileName(LicenseFile);
					RuntimeDependencies.Add(
						Path.Combine("$(PluginDir)", "Content", "webnative", "licenses", FileName),
						StagedFileType.NonUFS);
				}
			}

		}
	}
}
