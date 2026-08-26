// Copyright (c) 2026 StarTechnology. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "IWebNativeBrowserCore.h"
#include "RHI.h"
#include "Rendering/RenderingCommon.h"
#include "Styling/SlateBrush.h"
#include "Widgets/SLeafWidget.h"
#include "Engine/Texture2D.h"

class FWebNativeBrowserRHIHelper;
class FSlateTexture2DRHIRef;
class APlayerController;
class UPrimitiveComponent;
class UWidgetComponent;
class FWidgetPath;
struct FHitResult;
struct FWebNativeAlphaTileResult;

#if PLATFORM_LINUX
struct FWebNativeLinuxDmaBufFrame;
#ifndef WN_USE_VULKAN_DMABUF
#define WN_USE_VULKAN_DMABUF 1
#endif
#endif

class SWebNativeBrowser final : public SLeafWidget, public ISlateViewport, public IWebNativeBrowserView
{
	// Bring ISlateViewport overloads into scope to avoid -Woverloaded-virtual
	using ISlateViewport::OnFocusReceived;
	using ISlateViewport::OnCursorQuery;

public:
	SLATE_BEGIN_ARGS(SWebNativeBrowser)
		: _InitialURL(TEXT("https://www.bilibili.com"))
		, _ViewSize(FIntPoint(1280, 720))
		, _FrameRate(60)
		, _UseGpuAcceleratedRendering(true)
		, _AllowCpuRenderFallback(true)
		, _AcceptsInput(true)
		, _AutoFocusOnMouseDown(true)
		, _Use3DWidgetComponentMode(false)
		, _EnableMouseTransparency(false)
		, _MouseTransparencyAlphaThreshold(0)
		, _MouseTransparencyMaskBlockSize(1)
		, _AutoResizeToWidget(true)
		, _KeyboardF5(true)
		, _CtrlScale(false)
		, _TransparentBackground(true)
		, _MessageDispatchBudgetPerFrame(5000)
	{
	}
		SLATE_ARGUMENT(FString, InitialURL)
		SLATE_ARGUMENT(FIntPoint, ViewSize)
		SLATE_ARGUMENT(int32, FrameRate)
		SLATE_ARGUMENT(bool, UseGpuAcceleratedRendering)
		SLATE_ARGUMENT(bool, AllowCpuRenderFallback)
		SLATE_ARGUMENT(bool, AcceptsInput)
		SLATE_ARGUMENT(bool, AutoFocusOnMouseDown)
		SLATE_ARGUMENT(bool, Use3DWidgetComponentMode)
		SLATE_ARGUMENT(bool, EnableMouseTransparency)
		SLATE_ARGUMENT(int32, MouseTransparencyAlphaThreshold)
		SLATE_ARGUMENT(int32, MouseTransparencyMaskBlockSize)
		SLATE_ARGUMENT(bool, AutoResizeToWidget)
		SLATE_ARGUMENT(bool, KeyboardF5)
		SLATE_ARGUMENT(bool, CtrlScale)
		SLATE_ARGUMENT(bool, TransparentBackground)
		SLATE_ARGUMENT(int32, MessageDispatchBudgetPerFrame)
		SLATE_ARGUMENT(bool, ShowCefPerformanceMonitor)
		SLATE_ARGUMENT(bool, ShowDownloadNotification)
		SLATE_EVENT(FWebNativeBrowserNativeMessageDelegate, OnMessage)
		SLATE_EVENT(FWebNativeBrowserLoadStateDelegate, OnLoadStateChanged)
		SLATE_EVENT(FWebNativeBrowserUrlChangedDelegate, OnUrlChanged)
		SLATE_EVENT(FWebNativeBrowserBeforePopupDelegate, OnBeforePopup)
		SLATE_EVENT(FWebNativeBrowserLoadEndDelegate, OnLoadEnd)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	virtual ~SWebNativeBrowser() override;

	virtual TSharedRef<SWidget> GetSlateWidget() override { return AsShared(); }
	virtual void LoadURL(const FString& URL) override;
	virtual void GoBack() override;
	virtual void GoForward() override;
	virtual void Reload(bool bIgnoreCache) override;
	virtual void ExecuteJavaScript(const FString& Script) override;
	virtual void SendMessageToJavaScript(const FString& FunctionName, const FString& MessageBody) override;
	virtual void FlushMessagesToJS() override;
	virtual void ShowDevTools() override;
	virtual void CloseDevTools() override;
	virtual void ToggleDevTools() override;
	virtual void CloseBrowser() override;

	virtual void SetViewSize(FIntPoint InViewSize) override;
	virtual void SetRenderOptions(bool bInUseGpuAcceleratedRendering, bool bInAllowCpuRenderFallback) override;
	virtual void SetAcceptsInput(bool bInAcceptsInput) override;
	void SetSuspendPaint(bool bInSuspendPaint);
	virtual void SetAutoFocusOnMouseDown(bool bInAutoFocusOnMouseDown) override;
	virtual void SetUse3DWidgetComponentMode(bool bEnabled) override;
	virtual void SetTransparentScenePrimitiveEvents(bool bEnabled, APlayerController* OwningPlayer) override;
	virtual void SetMouseTransparency(bool bInEnableMouseTransparency, int32 InAlphaThreshold, int32 InMaskBlockSize = 1) override;
	virtual void SetAutoResizeToWidget(bool bInAutoResizeToWidget) override;
	void SetKeyboardShortcuts(bool bInKeyboardF5, bool bInCtrlScale);
	virtual void SetMessageDispatchBudgetPerFrame(int32 InMessageDispatchBudgetPerFrame) override;
	virtual void SetForwardUEKeyEvents(bool bInForwardUEKeyEvents) override;
	virtual void SetOnMessage(FWebNativeBrowserNativeMessageDelegate InOnMessage) override;
	virtual void SetOnLoadStateChanged(FWebNativeBrowserLoadStateDelegate InOnLoadStateChanged) override;
	virtual void SetOnUrlChanged(FWebNativeBrowserUrlChangedDelegate InOnUrlChanged) override;
	virtual void SetOnBeforePopup(FWebNativeBrowserBeforePopupDelegate InOnBeforePopup) override;
	virtual void SetOnLoadEnd(FWebNativeBrowserLoadEndDelegate InOnLoadEnd) override;
	bool ForwardKeyDownFromInputPreProcessor(const FKeyEvent& InKeyEvent);
	bool ForwardKeyUpFromInputPreProcessor(const FKeyEvent& InKeyEvent);
	bool ForwardMouseButtonDownFromInputPreProcessor(const FPointerEvent& MouseEvent);
	bool ForwardMouseButtonUpFromInputPreProcessor(const FPointerEvent& MouseEvent);
	bool OwnsMouseButtonSequence(const FKey& Button) const;
	bool ContainsScreenPosition(const FVector2D& ScreenPosition) const;
	void RequestCpuRenderingFallback();
	/** Internal input-preprocessor hook: restore a deferred PlayerController flag lease after all physical mouse buttons are up. */
	void FlushDeferredTransparentScenePrimitivePlayerFlags();

	/** UE应用失去焦点时(Alt+Tab等), 向活动浏览器实例注入清理事件释放所有按键状态 */
	static void InjectInputResetToActiveBrowser();

	/** 控制活动浏览器实例的CEF渲染: bHidden=true停止渲染, bHidden=false恢复渲染 */
	static void SetActiveBrowserHidden(bool bHidden);

	/** Request closure of every CEF browser owned by this UE process. Returns the tracked count before closing. */
	static int32 RequestCloseAllBrowsersForShutdown();

	/** Number of CEF browsers that have not completed OnBeforeClose yet. */
	static int32 GetTrackedBrowserCount();

	/** Release shutdown-only tracking references before CefShutdown(). */
	static void ClearTrackedBrowsersForShutdown();

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual bool SupportsKeyboardFocus() const override { return bAcceptsInput; }
	virtual FReply OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent) override;
	virtual void OnFocusLost(const FFocusEvent& InFocusEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;
	virtual void OnMouseCaptureLost(const FCaptureLostEvent& CaptureLostEvent) override;
	virtual FReply OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const override;
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent) override;
	virtual FReply OnTouchStarted(const FGeometry& MyGeometry, const FPointerEvent& InTouchEvent) override;
	virtual FReply OnTouchMoved(const FGeometry& MyGeometry, const FPointerEvent& InTouchEvent) override;
	virtual FReply OnTouchEnded(const FGeometry& MyGeometry, const FPointerEvent& InTouchEvent) override;
	virtual FReply OnTouchForceChanged(const FGeometry& MyGeometry, const FPointerEvent& InTouchEvent) override;
	virtual FIntPoint GetSize() const override;
	virtual FSlateShaderResource* GetViewportRenderTargetTexture() const override;
	virtual bool RequiresVsync() const override { return false; }

	bool ShouldMouseEventPassThrough(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent, bool bRequireAccurateAlpha = false) const;

	/** True when the owner explicitly configured this browser for a world-space UWidgetComponent. */
	bool IsWidgetComponentMode() const { return bUse3DWidgetComponentMode; }

private:
	struct FImpl;

	void CreateTexture(int32 InWidth, int32 InHeight);
	void UpdateTexture(TArray<uint8>&& FrameData, int32 InWidth, int32 InHeight, TArray<FIntRect>&& DirtyRects);
	TSharedPtr<FThreadSafeCounter, ESPMode::ThreadSafe> AcquireCpuUploadBuffer(int32 Size, uint8*& OutData);
	void UpdateDragTexture(TArray<uint8>&& PixelData, const FIntPoint& PixelSize);
	void ReleaseDragTexture();
	void CloseBrowserInstance();
	void CreateBrowserInstance(bool bInUseGpuAcceleratedRendering);
	void RecreateBrowserInstance(bool bInUseGpuAcceleratedRendering);
	void UpdatePaintLifecycleState();
	bool ShouldDropPaintCallbacks() const;
	bool CreateAcceleratedTexture(int32 InWidth, int32 InHeight);
	void ReleaseAcceleratedTexture();
	void ProcessPendingTextureDestructions();
#if PLATFORM_WINDOWS
	bool CopyAcceleratedFrame(void* SharedHandle, int32 InWidth, int32 InHeight, TArray<FIntRect>&& DirtyRects, bool& bOutRetryLater);
#endif
#if PLATFORM_LINUX
	bool CopyAcceleratedFrame(const FWebNativeLinuxDmaBufFrame& Frame, int32 InWidth, int32 InHeight, TArray<FIntRect>&& DirtyRects, bool& bOutRetryLater);
#endif
	FIntPoint GetBrowserPoint(const FGeometry& MyGeometry, const FVector2D& ScreenPosition) const;
	bool ShouldMousePositionPassThrough(const FGeometry& MyGeometry, const FVector2D& ScreenPosition, bool bRequireAccurateAlpha = false) const;
	bool IsInputSequenceActive() const;
	void ApplyPending3DWidgetComponentMode();
	void Release3DWidgetPressedButtons();
	bool CanDispatchTransparentScenePrimitiveEvents() const;
	void TryActivateTransparentScenePrimitiveEventBridge();
	void RestoreTransparentScenePrimitivePlayerFlags();
	bool TryTraceScenePrimitive(const FVector2D& ScreenPosition, UPrimitiveComponent*& OutComponent, FHitResult* OutHitResult = nullptr) const;
	void UpdateTransparentScenePrimitiveHover(const FGeometry& MyGeometry, const FVector2D& ScreenPosition, bool bTransparencyAlreadyConfirmed = false);
	void TransitionTransparentScenePrimitiveHover(UPrimitiveComponent* NewComponent);
	bool HandleTransparentScenePrimitiveButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void HandleTransparentScenePrimitiveButtonUp(const FPointerEvent& MouseEvent);
	void ReleaseStaleTransparentSceneButtonBeforeDown(const FPointerEvent& MouseEvent);
	bool OwnsTransparentScenePrimitivePointer(const FPointerEvent& MouseEvent) const;
	bool OwnsTransparentScenePrimitiveButton(const FPointerEvent& MouseEvent) const;
	bool AddTransparentSceneViewportRoute(const FPointerEvent& MouseEvent);
	void ReleaseCompletedTransparentSceneViewportRoutes();
	bool BuildSceneWidgetComponentPath(const FVector2D& ScreenPosition, FWidgetPath& OutPath, UWidgetComponent*& OutWidgetComponent) const;
	bool OwnsTransparentSceneWidgetComponentPointer(const FPointerEvent& MouseEvent) const;
	void AddTransparentSceneWidgetComponentRoute(const FPointerEvent& MouseEvent);
	void RemoveTransparentSceneWidgetComponentRoute(const FPointerEvent& MouseEvent);
	void ReleaseCompletedTransparentSceneWidgetComponentRoutes();
	void BeginTransparentScenePrimitiveViewportRoute();
	void EndTransparentScenePrimitiveViewportRoute();
	void ReleaseCompletedTransparentScenePrimitiveButtons();
	void ClearTransparentScenePrimitiveEventState(bool bDispatchBalancedEvents);
	void DispatchTransparentScenePrimitiveHover(UPrimitiveComponent* PreviousComponent, UPrimitiveComponent* NewComponent);
	void DispatchTransparentScenePrimitiveClicked(UPrimitiveComponent* Component, const FKey& Button);
	void DispatchTransparentScenePrimitiveReleased(UPrimitiveComponent* Component, const FKey& Button);
	void FlushDeferredTransparentScenePrimitiveClear();
	void ResetHitTestAlphaCache();
	void ResetHitTestAlphaCacheLocked();
	void InvalidateAcceleratedHitTestAlpha(const TArray<FIntRect>& DirtyRects, const FIntPoint& SourceSize) const;
	void StoreHitTestAlpha(const TArray<uint8>& FrameData, int32 InWidth, int32 InHeight, const TArray<FIntRect>& DirtyRects);
	bool ReadAcceleratedHitTestAlpha(const FIntPoint& BrowserPoint, uint8& OutAlpha, bool bAllowReadbackRequest, bool bBlockingReadback = false) const;
	void ConsumeCompletedGpuAlphaTile(const FWebNativeAlphaTileResult& Result) const;
	bool TryReadGpuAlphaCacheLocked(const FIntRect& QueryRect, uint8& OutAlpha, FIntPoint& OutMissingTileOrigin) const;
	void SendMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent, bool bLeaving);
	void SendMouseClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent, bool bMouseUp, int32 ClickCount);
	FReply MakeInputHandledReply();
	void DrawPerformanceOverlay(const FGeometry& AllottedGeometry, FSlateWindowElementList& OutDrawElements, int32& LayerId) const;
	void RenderDeviceDiagnostics(const FGeometry& AllottedGeometry, FSlateWindowElementList& OutDrawElements, int32& LayerId) const;

	FImpl* Impl = nullptr;
	mutable FSlateBrush Brush;
	UTexture2D* Texture = nullptr;
	mutable FSlateBrush DragImageBrush;
	UTexture2D* DragImageTexture = nullptr;
	FIntPoint DragImagePixelSize = FIntPoint::ZeroValue;
	FIntPoint DragImageDisplaySize = FIntPoint::ZeroValue;
	FIntPoint DragImagePosition = FIntPoint::ZeroValue;
	FIntPoint DragImageHotspot = FIntPoint::ZeroValue;
	bool bDragImageVisible = false;
	FString CurrentURL;
	int32 BrowserFrameRate = 60;
	FWebNativeBrowserNativeMessageDelegate OnMessage;
	FWebNativeBrowserLoadStateDelegate OnLoadStateChanged;
	FWebNativeBrowserUrlChangedDelegate OnUrlChanged;
	FWebNativeBrowserBeforePopupDelegate OnBeforePopup;
	FWebNativeBrowserLoadEndDelegate OnLoadEnd;
	FWebNativeBrowserRHIHelper* RHIHelper = nullptr;
	FSlateTexture2DRHIRef* AcceleratedTexture = nullptr;
	FIntPoint TextureSize = FIntPoint::ZeroValue;
	FIntPoint AcceleratedTextureSize = FIntPoint::ZeroValue;
	FIntPoint ViewSize = FIntPoint(1280, 720);
	FIntPoint PendingViewSize = FIntPoint(1280, 720);
	double LastResizeRequestTime = 0.0;
	static constexpr double ResizeDebounceDelaySeconds = 0.2;
	static constexpr int32 GpuAlphaTileSide = 16;
	static constexpr int32 GpuAlphaTilePixelCount = GpuAlphaTileSide * GpuAlphaTileSide;
	static constexpr int32 GpuAlphaTileMaskWordCount = GpuAlphaTilePixelCount / 64;
	static constexpr int32 GpuAlphaTileCapacity = 32;

	struct FGpuAlphaTileKey
	{
		uint64 CacheEpoch = 0;
		FIntPoint SourceSize = FIntPoint::ZeroValue;
		FIntPoint Origin = FIntPoint::ZeroValue;

		bool operator==(const FGpuAlphaTileKey& Other) const
		{
			return CacheEpoch == Other.CacheEpoch
				&& SourceSize == Other.SourceSize
				&& Origin == Other.Origin;
		}
	};

	struct FGpuAlphaTile
	{
		FGpuAlphaTileKey Key;
		FIntPoint ValidSize = FIntPoint::ZeroValue;
		uint8 Alpha[GpuAlphaTilePixelCount] = {};
		uint64 ValidMask[GpuAlphaTileMaskWordCount] = {};
		uint64 LastUseSerial = 0;
	};

	struct FPendingGpuAlphaTile
	{
		bool bActive = false;
		uint64 RequestId = 0;
		FGpuAlphaTileKey Key;
		FIntPoint ValidSize = FIntPoint::ZeroValue;
		FTextureRHIRef SourceTexture;
		uint64 InvalidMask[GpuAlphaTileMaskWordCount] = {};
	};

	mutable TArray<uint8> HitTestAlpha;
	mutable FIntPoint HitTestAlphaSize = FIntPoint::ZeroValue;
	mutable FIntPoint HitTestAlphaSourceSize = FIntPoint::ZeroValue;
	int32 HitTestAlphaBlockSize = 1;
	mutable int32 CachedHitTestAlphaBlockSize = 0;
	mutable bool bHitTestAlphaUsesGpu = false;
	mutable TArray<FGpuAlphaTile, TInlineAllocator<GpuAlphaTileCapacity>> GpuAlphaTiles;
	mutable FPendingGpuAlphaTile PendingGpuAlphaTile;
	mutable uint64 GpuAlphaCacheEpoch = 1;
	mutable uint64 NextGpuAlphaRequestId = 1;
	mutable uint64 GpuAlphaUseSerial = 0;
	mutable double LastGpuAlphaReadbackAttemptSeconds = 0.0;
	bool bAcceptsInput = true;

	// Explicit per-browser input mode. In 3D, FWidget3DHitTester owns pointer
	// routing and the 2D fullscreen alpha pass-through path is disabled.
	bool bUse3DWidgetComponentMode = false;
	TOptional<bool> PendingUse3DWidgetComponentMode;
	uint64 Use3DWidgetComponentModeConfigurationSerial = 0;

	struct FScenePrimitivePointerKey
	{
		int32 UserIndex = 0;
		int32 PointerIndex = 0;
		FKey Button;

		bool operator==(const FScenePrimitivePointerKey& Other) const
		{
			return UserIndex == Other.UserIndex
				&& PointerIndex == Other.PointerIndex
				&& Button == Other.Button;
		}

		friend uint32 GetTypeHash(const FScenePrimitivePointerKey& Key)
		{
			const uint32 PointerHash = HashCombine(
				::GetTypeHash(Key.UserIndex),
				::GetTypeHash(Key.PointerIndex));
			return HashCombine(PointerHash, GetTypeHash(Key.Button));
		}
	};

	struct FSceneWidgetComponentPointerKey
	{
		int32 UserIndex = 0;
		int32 PointerIndex = 0;

		bool operator==(const FSceneWidgetComponentPointerKey& Other) const
		{
			return UserIndex == Other.UserIndex
				&& PointerIndex == Other.PointerIndex;
		}

		friend uint32 GetTypeHash(const FSceneWidgetComponentPointerKey& Key)
		{
			return HashCombine(
				::GetTypeHash(Key.UserIndex),
				::GetTypeHash(Key.PointerIndex));
		}
	};

	bool bEnableTransparentScenePrimitiveEvents = false;
	TWeakObjectPtr<APlayerController> TransparentScenePrimitivePlayer;
	TWeakObjectPtr<APlayerController> TransparentScenePrimitiveLeasePlayer;
	TWeakObjectPtr<UPrimitiveComponent> HoveredTransparentScenePrimitive;
	TMap<FScenePrimitivePointerKey, TWeakObjectPtr<UPrimitiveComponent>> PressedTransparentScenePrimitives;
	TSet<FScenePrimitivePointerKey> TransparentSceneViewportRoutes;
	TSet<FSceneWidgetComponentPointerKey> TransparentSceneWidgetComponentRoutes;
	bool bOwnsTransparentScenePrimitivePlayerFlags = false;
	bool bTransparentScenePrimitivePlayerFlagsRestorePending = false;
	bool bTransparentScenePrimitiveConflictLogged = false;
	bool bTransparentScenePrimitiveRouteLimitLogged = false;
	bool bSavedEnableMouseOverEvents = false;
	bool bSavedEnableClickEvents = false;
	uint64 TransparentScenePrimitiveActivationFrame = 0;
	uint64 TransparentScenePrimitiveConfigurationSerial = 0;
	int32 TransparentScenePrimitiveDispatchDepth = 0;
	int32 TransparentScenePrimitiveViewportRouteDepth = 0;
	bool bTransparentScenePrimitiveClearPending = false;
	bool bTransparentScenePrimitiveBalancedClearPending = false;

	// These flags are read by CEF paint callbacks and written by the game
	// thread (or by SetSuspendPaint), so they must never be plain bools.
	// A missing Slate window deliberately means "active" for headless Linux
	// and Pixel Streaming; only a real SWindow reporting minimized is automatic
	// suspension.
	TAtomic<bool> bSuspendPaint{ false };
	TAtomic<bool> bWindowMinimized{ false };
	TAtomic<bool> bBrowserClosing{ false };
	bool bAppliedPaintSuspended = false; // Game-thread transition cache.
	bool bSlateWidgetDestructing = false;

	bool bAutoFocusOnMouseDown = true;
	bool bEnableMouseTransparency = true;
	uint64 AcceptsInputConfigurationSerial = 0;
	uint64 MouseTransparencyConfigurationSerial = 0;
	bool bAutoResizeToWidget = true;
	bool bUseGpuAcceleratedRendering = true;
	bool bAllowCpuRenderFallback = true;
	bool bShowCefPerformanceMonitor = false;
	bool bShowDownloadNotification = true;
	bool bKeyboardF5 = false;
	bool bCtrlScale = false;
	bool bForwardUEKeyEvents = false;
	bool bHasFirstFrame = false;
	bool bTransparentBackground = true;
	int32 MessageDispatchBudgetPerFrame = 5000;
	int32 MouseTransparencyAlphaThreshold = 0;
	uint8 CapturedMouseButtonMask = 0;
	mutable FCriticalSection HitTestAlphaLock;
	mutable FCriticalSection AcceleratedTextureLock;
	FIntPoint PendingAcceleratedTextureSize = FIntPoint::ZeroValue;
	TAtomic<bool> bHasAcceleratedFrame{ false };
	TAtomic<bool> bAcceleratedFrameDirty{ false };
	TAtomic<bool> bCpuRenderingFallbackRequested{ false };

	// Deferred texture destruction queue. Slate may still have cached draw
	// elements for several frames after a resize, so retirement has two stages:
	// wait for the Slate hand-off window, then insert and poll a real GPU fence.
	// A frame count alone is not proof that the GPU has stopped using a texture.
	struct FPendingTextureDestruction
	{
		struct FFenceSubmissionState
		{
			TAtomic<bool> bWriteIssued{ false };
		};

		FSlateTexture2DRHIRef* Texture = nullptr;
		uint64 EstimatedBytes = 0;
		uint64 EarliestFenceFrame = 0;
		FGPUFenceRHIRef RetirementFence;
		TSharedPtr<FFenceSubmissionState, ESPMode::ThreadSafe> FenceSubmissionState;
		double FenceQueuedSeconds = 0.0;
	};
	TArray<FPendingTextureDestruction> PendingTextureDestructions;
	bool bLoggedTextureRetirementFailure = false;

	// CPU rendering upload buffer pool (avoids per-frame Malloc/Free)
	static constexpr int32 CpuUploadPoolSize = 4;
	struct FCpuUploadSlot
	{
		TArray<uint8> Buffer;
		TSharedPtr<FThreadSafeCounter, ESPMode::ThreadSafe> InUse;
		FCpuUploadSlot() : InUse(MakeShared<FThreadSafeCounter, ESPMode::ThreadSafe>(0)) {}
	};
	mutable FCpuUploadSlot CpuUploadSlots[CpuUploadPoolSize];
#if PLATFORM_LINUX && WN_USE_VULKAN_DMABUF
	// Set after CopyDmaBufToTexture writes to the persistent texture via an
	// external vkQueueSubmit that RHI is unaware of.  Tick schedules an
	// ENQUEUE_RENDER_COMMAND that calls RHICmdList.Transition(Unknown→SRVGraphics)
	// on the persistent texture to re-synchronise RHI's internal layout tracking.
	bool bNeedsDmaBufLayoutResync = false;
#endif

	// Async GPU copy queue. OnAcceleratedPaint (CEF IPC thread) pushes the
	// latest frame handle here, and a deferred RHI command consumes it on
	// the UE RHI thread. We *never* call FlushRenderingCommands or any
	// game-thread-only API from the CEF IPC thread — that asserts.
	struct FPendingAcceleratedFrame
	{
		void* SharedHandle = nullptr;
		int32 Width = 0;
		int32 Height = 0;
		TArray<FIntRect> DirtyRects;
	};
	mutable FCriticalSection PendingFrameMutex;
	TUniquePtr<FPendingAcceleratedFrame> LatestPendingFrame;
};
