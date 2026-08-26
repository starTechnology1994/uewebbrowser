// Copyright (c) 2026 StarTechnology. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "RHI.h"
#include "Templates/Function.h"
#include "WebNativeVersionCompatibility.h"

#define WN_VULKAN_HAS_EXTERNAL_IMAGE_CALLBACK WN_UE5_5_PLUS
#define WN_VULKAN_HAS_RUN_ON_QUEUE WN_UE5_6_PLUS
#define WN_D3D12_HAS_NO_MGPU_DEVICE WN_UE5_8_PLUS

class FSlateTexture2DRHIRef;
#if PLATFORM_WINDOWS
struct FWebNativeD3D12AlphaSubmission;
#endif

enum class EWebNativeAlphaTileRequestResult : uint8
{
	Failed,
	Busy,
	Started,
	Completed
};

enum class EWebNativeAlphaTilePollResult : uint8
{
	Idle,
	Pending,
	Ready,
	Failed
};

struct FWebNativeAlphaTileResult
{
	static constexpr int32 TileEdge = 16;
	static constexpr int32 PixelCapacity = TileEdge * TileEdge;

	uint64 RequestId = 0;
	FTextureRHIRef SourceTexture;
	FIntPoint Origin = FIntPoint::ZeroValue;
	FIntPoint Size = FIntPoint::ZeroValue;
	uint8 Alpha[PixelCapacity] = {};

	bool IsValid() const
	{
		return RequestId != 0
			&& SourceTexture.IsValid()
			&& Size.X > 0 && Size.Y > 0
			&& Size.X <= TileEdge && Size.Y <= TileEdge;
	}
};

#if PLATFORM_WINDOWS
#include "Windows/WindowsHWrapper.h"
#include "Microsoft/COMPointer.h"

#include "ID3D12DynamicRHI.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include "d3d11.h"
#include "d3d11_1.h"
#include "d3d12.h"

#include "Windows/HideWindowsPlatformTypes.h"
#endif

#if PLATFORM_LINUX
#include "IVulkanDynamicRHI.h"
#endif

#if !WN_ENGINE_HAS_FANSISTRING
using FAnsiString = FString;
#else
#include "Containers/AnsiString.h"
#endif

#if !WN_VULKAN_HAS_EXTERNAL_IMAGE_CALLBACK
struct FVulkanRHIExternalImageDeleteCallbackInfo
{
	void* UserData = nullptr;
	void (*Function)(void*) = nullptr;
};
#endif

#if PLATFORM_LINUX
#ifndef WN_USE_VULKAN_DMABUF
#define WN_USE_VULKAN_DMABUF 1
#endif
#endif

namespace WebNativeRHICompat
{
#if PLATFORM_LINUX
	inline void RunOnVulkanGraphicsQueue(
		IVulkanDynamicRHI* VulkanRHI,
		TFunction<void(VkQueue)>&& CodeToRun,
		bool bWaitForSubmission)
	{
#if WN_VULKAN_HAS_RUN_ON_QUEUE
		VulkanRHI->RHIRunOnQueue(EVulkanRHIRunOnQueueType::Graphics, MoveTemp(CodeToRun), bWaitForSubmission);
#else
		VkQueue Queue = VulkanRHI->RHIGetGraphicsVkQueue();
		if (Queue != VK_NULL_HANDLE)
		{
			CodeToRun(Queue);
		}
		else if (bWaitForSubmission)
		{
			CodeToRun(VK_NULL_HANDLE);
		}
#endif
	}

	inline TArray<FAnsiString> GetLoadedVulkanDeviceExtensions(IVulkanDynamicRHI* VulkanRHI)
	{
#if WN_VULKAN_HAS_EXTERNAL_IMAGE_CALLBACK
		return VulkanRHI->RHIGetLoadedDeviceExtensions();
#else
		TArray<FAnsiString> Result;
		VkPhysicalDevice PhysDev = VulkanRHI->RHIGetVkPhysicalDevice();
		if (PhysDev == VK_NULL_HANDLE)
		{
			return Result;
		}
		TArray<VkExtensionProperties> All = VulkanRHI->RHIGetAllDeviceExtensions(PhysDev);
		Result.Reserve(All.Num());
		for (const VkExtensionProperties& Ext : All)
		{
			Result.Emplace(Ext.extensionName);
		}
		return Result;
#endif
	}
#endif // PLATFORM_LINUX

#if PLATFORM_WINDOWS
	inline ID3D12Device* GetD3D12PrimaryDevice(ID3D12DynamicRHI* D3D12RHI)
	{
#if WN_D3D12_HAS_NO_MGPU_DEVICE
		return D3D12RHI->RHIGetDevice_NoMGPU();
#else
		return D3D12RHI->RHIGetDevice(0);
#endif
	}
#endif // PLATFORM_WINDOWS
} // namespace WebNativeRHICompat

#if PLATFORM_LINUX && WN_USE_VULKAN_DMABUF
struct FWebNativeLinuxDmaBufPlane
{
	int32 FileDescriptor = -1;
	int32 Stride = 0;
	int32 Offset = 0;
	int32 Size = 0;
};

struct FWebNativeLinuxDmaBufFrame
{
	uint64 Modifier = 0;
	bool bBGRA = true;
	TArray<FWebNativeLinuxDmaBufPlane> Planes;
	FIntPoint SourceSize = FIntPoint::ZeroValue;
};
#endif

const TCHAR* RHIInterfaceTypeToString(ERHIInterfaceType InType);

class FWebNativeBrowserRHIHelper
{
public:
	FWebNativeBrowserRHIHelper();
	~FWebNativeBrowserRHIHelper();

	static bool IsSupported();
	static uint64 GetRHIAdapterLuid();

	static void* DuplicateSharedHandle(void* SourceHandle);
	static void CloseSharedHandle(void* Handle);

	bool IsReady() const;
	FSlateTexture2DRHIRef* CreateTexture(const FIntPoint& TextureSize);
	void ReleaseTexture(FSlateTexture2DRHIRef*& SlateTexture);
	bool CopySharedTextureSync(FSlateTexture2DRHIRef* SlateTexture, void* SharedHandle, const FIntRect& DirtyRect);
	EWebNativeAlphaTileRequestResult RequestTextureAlphaTile(
		FSlateTexture2DRHIRef* SlateTexture,
		const FIntPoint& TileOrigin,
		uint64 RequestId,
		FWebNativeAlphaTileResult& OutCompletedResult);
	EWebNativeAlphaTilePollResult PollTextureAlphaTile(
		FWebNativeAlphaTileResult& OutResult,
		double BlockingDeadlineSeconds = 0.0);

#if PLATFORM_LINUX && WN_USE_VULKAN_DMABUF
	bool CreateHostVisibleTexture(const FIntPoint& TextureSize, FSlateTexture2DRHIRef*& OutTexture);
	bool UploadDmaBufToHostImage(const FWebNativeLinuxDmaBufFrame& Frame, FSlateTexture2DRHIRef* DestTexture, const FIntPoint& ContentSize);
#endif

#if PLATFORM_LINUX && WN_USE_VULKAN_DMABUF
	bool CreateSlateTextureFromDmaBuf(const FWebNativeLinuxDmaBufFrame& Frame, FSlateTexture2DRHIRef*& OutTexture, FIntPoint& OutImageSize);

	bool ImportAndBarrierDmaBuf(const FWebNativeLinuxDmaBufFrame& Frame,
		uint64& OutVkImage, uint64& OutVkMemory, void*& OutPayload,
		FIntPoint& OutRhiSize, FIntPoint& OutContentSize, bool& bOutBGRA);

	bool WrapDmaBufAsSlateTexture(
		uint64 InVkImage, uint64 InVkMemory, void* InPayload,
		const FIntPoint& RhiSize, const FIntPoint& ContentSize, bool bBGRA,
		FSlateTexture2DRHIRef*& OutTexture, FIntPoint& OutImageSize);

	bool WrapDmaBufAsRHITexture(
		uint64 InVkImage, uint64 InVkMemory, void* InPayload,
		const FIntPoint& RhiSize, const FIntPoint& ContentSize, bool bBGRA,
		FTextureRHIRef& OutRHITexture, FIntPoint& OutImageSize);

	bool CopyDmaBufToTexture(const FWebNativeLinuxDmaBufFrame& Frame, FSlateTexture2DRHIRef* DestTexture, const FIntPoint& ContentSize);
#endif

private:
	bool EnsureShareable(FSlateTexture2DRHIRef* SlateTexture);
	EWebNativeAlphaTileRequestResult RequestTextureAlphaTileD3D12(
		FSlateTexture2DRHIRef* SlateTexture,
		const FIntPoint& TileOrigin,
		uint64 RequestId);
	EWebNativeAlphaTilePollResult PollTextureAlphaTileD3D12(
		FWebNativeAlphaTileResult& OutResult,
		double BlockingDeadlineSeconds);

#if PLATFORM_LINUX && WN_USE_VULKAN_DMABUF
	bool ImportDmaBufSharedImage(const FWebNativeLinuxDmaBufFrame& Frame, const FIntPoint& ImageSize, VkImage& OutImage, VkDeviceMemory& OutMemory);
	void ReleaseDmaBufSharedImage(VkImage Image, VkDeviceMemory Memory);

	bool EnsureDmaBufAcquireBarrier(VkImage Image);
#endif

	static void OnExternalDmaBufImageDeleted(void* UserData);

	TMap<FSlateTexture2DRHIRef*, TSharedPtr<void>> SlateTextureHandles;

#if PLATFORM_WINDOWS
	TComPtr<ID3D11Device> D3D11Device;
	TComPtr<ID3D11DeviceContext> D3D11DeviceContext;
	D3D_FEATURE_LEVEL D3D11DeviceFeatureLevel = D3D_FEATURE_LEVEL_11_0;
	TComPtr<ID3D11Query> D3D11CopySyncQuery;

	FSlateTexture2DRHIRef* CachedDestSlateTexture = nullptr;
	TComPtr<ID3D11Texture2D> CachedDestD3D11Texture;

	TComPtr<ID3D11Texture2D> AlphaReadbackTexture;
	DXGI_FORMAT AlphaReadbackTextureFormat = DXGI_FORMAT_UNKNOWN;
	FWebNativeAlphaTileResult AlphaReadbackPendingResult;
	bool bAlphaReadbackPending = false;
	bool bAlphaReadbackDisabled = false;
	double AlphaReadbackStageStartSeconds = 0.0;
	TSharedPtr<FWebNativeD3D12AlphaSubmission, ESPMode::ThreadSafe> D3D12AlphaSubmission;
	TAtomic<bool> bD3DDeviceRemoved{ false };
	bool bLoggedCefSharedTextureOpenFailure = false;
#elif PLATFORM_LINUX && WN_USE_VULKAN_DMABUF
	VkDevice VulkanDevice = VK_NULL_HANDLE;
	VkPhysicalDevice VulkanPhysicalDevice = VK_NULL_HANDLE;
	uint32_t VulkanQueueFamilyIndex = UINT32_MAX;
	VkQueue VulkanQueue = VK_NULL_HANDLE;
	VkCommandPool VulkanCommandPool = VK_NULL_HANDLE;
	FCriticalSection VulkanCommandPoolLock;
	bool bVulkanInitialized = false;

	bool TryAcquireVulkanDevice();
	void ReleaseVulkanDevice();
	bool AllocateVulkanCommandBuffer(VkCommandBuffer& OutCommandBuffer);
	void FreeVulkanCommandBuffer(VkCommandBuffer CommandBuffer);

	struct FPendingDmaBufCleanup
	{
		VkFence Fence = VK_NULL_HANDLE;
		VkCommandBuffer CmdBuf = VK_NULL_HANDLE;
		VkImage SrcImage = VK_NULL_HANDLE;
		VkDeviceMemory SrcMemory = VK_NULL_HANDLE;
		FIntPoint ContentSize;
	};

	TArray<FPendingDmaBufCleanup*> PendingDmaBufCleanups;
	FCriticalSection PendingDmaBufCleanupLock;

	struct FHostMappedTexture
	{
		VkImage Image = VK_NULL_HANDLE;
		VkDeviceMemory Memory = VK_NULL_HANDLE;
		void* MappedPtr = nullptr;
		VkDeviceSize MappedSize = 0;
		VkDeviceSize RowPitch = 0;
		FIntPoint Size = FIntPoint::ZeroValue;
	};
	TMap<FSlateTexture2DRHIRef*, FHostMappedTexture> HostMappedTextures;
	FCriticalSection HostMappedTexturesLock;

	struct FStagingBuffer
	{
		uint8* Data = nullptr;
		int32 Size = 0;
		bool bInUse = false;
	};
	static constexpr int32 STAGING_POOL_SIZE = 4;
	FStagingBuffer StagingPool[STAGING_POOL_SIZE];
	int32 StagingPoolIndex = 0;
	FCriticalSection StagingPoolLock;

public:
	void ProcessAsyncDmaBufCleanup();
#endif
};
