// Copyright (c) 2026 StarTechnology. All rights reserved.

#pragma once

#include "Components/Widget.h"
#include "WebNativeBrowserWidget.generated.h"

class IWebNativeBrowserView;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWebNativeBrowserMessageReceivedEvent, const FString&, FunctionName, const FString&, MessageBody);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FWebNativeBrowserLoadStateChangedEvent, bool, bIsLoading, bool, bCanGoBack, bool, bCanGoForward);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWebNativeBrowserUrlChangedEvent, const FString&, URL);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWebNativeBrowserBeforePopupEvent, const FString&, TargetURL, const FString&, TargetFrameName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWebNativeBrowserLoadEndEvent, const FString&, URL, int32, HttpStatusCode);

UCLASS(BlueprintType, Blueprintable, meta = (DisplayName = "WebNative Browser"))
class WEBNATIVEBROWSER_API UWebNativeBrowserWidget : public UWidget
{
	GENERATED_BODY()

public:
	UWebNativeBrowserWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Page")
	FString InitialURL = TEXT("https://www.bilibili.com");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Page", meta = (ClampMin = "1"))
	FIntPoint ViewSize = FIntPoint(1280, 720);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Page")
	bool bAutoResizeToWidget = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Rendering", meta = (ClampMin = "1", ClampMax = "120"))
	int32 FrameRate = 60;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Rendering")
	bool bUseGpuAcceleratedRendering = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Rendering", meta = (EditCondition = "bUseGpuAcceleratedRendering"))
	bool bAllowCpuRenderFallback = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Input")
	bool bAcceptsInput = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Input")
	bool bAutoFocusOnMouseDown = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Input")
	bool bEnableMouseTransparency = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Input", meta = (ClampMin = "0", ClampMax = "255", EditCondition = "bEnableMouseTransparency"))
	int32 MouseTransparencyAlphaThreshold = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Input", meta = (ClampMin = "1", ClampMax = "16", EditCondition = "bEnableMouseTransparency"))
	int32 MouseTransparencyMaskBlockSize = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Message", meta = (ClampMin = "1", ClampMax = "100000"))
	int32 MessageDispatchBudgetPerFrame = 5000;

	/** 开启后，即使焦点在UE场景中，键盘事件也会转发给CEF（用于撤销重做等双重处理场景） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebNative|Input")
	bool bForwardUEKeyEvents = false;

	UPROPERTY(BlueprintAssignable, Category = "WebNative|Message")
	FWebNativeBrowserMessageReceivedEvent OnMessageReceived;

	UPROPERTY(BlueprintAssignable, Category = "WebNative|Navigation")
	FWebNativeBrowserLoadStateChangedEvent OnLoadStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "WebNative|Navigation")
	FWebNativeBrowserUrlChangedEvent OnUrlChanged;

	UPROPERTY(BlueprintAssignable, Category = "WebNative|Navigation")
	FWebNativeBrowserBeforePopupEvent OnBeforePopup;

	UPROPERTY(BlueprintAssignable, Category = "WebNative|Navigation")
	FWebNativeBrowserLoadEndEvent OnLoadEnd;

	UFUNCTION(BlueprintCallable, Category = "WebNative|Page")
	void LoadURL(const FString& URL);

	/** 后退到上一页（如果 bCanGoBack 为 true） */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Navigation")
	void GoBack();

	/** 前进到下一页（如果 bCanGoForward 为 true） */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Navigation")
	void GoForward();

	/** 重新加载当前页 */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Navigation")
	void Reload(bool bIgnoreCache = false);

	UFUNCTION(BlueprintCallable, Category = "WebNative|Script")
	void ExecuteJavaScript(const FString& Script);

	UFUNCTION(BlueprintCallable, Category = "WebNative|Message")
	void SendMessageToJS(const FString& FunctionName, const FString& MessageBody);

	void FlushMessagesToJS();

	/** 将输入焦点从 CEF 浏览器强制切换到 UE 游戏视口。
	 *  同时释放 Slate 的鼠标捕获（PointerCapture），
	 *  确保后续鼠标移动/抬起事件直接到达视口而非 CEF。
	 *  适用场景：从 WebView 拖拽物品到 3D 场景时调用，放置后 CEF 恢复交互。 */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Input")
	void SetFocusToGameViewport();

	UFUNCTION(BlueprintCallable, Category = "WebNative|Debug")
	void ShowDevTools();

	UFUNCTION(BlueprintCallable, Category = "WebNative|Debug")
	void CloseDevTools();

	UFUNCTION(BlueprintCallable, Category = "WebNative|Debug")
	void ToggleDevTools();

	/** Set the CEF browser view size at runtime (fixed-resolution mode, bAutoResizeToWidget must be false). */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Page")
	void SetViewResolution(FIntPoint NewSize);

	/** Enable or disable automatic resize to match the widget's on-screen geometry. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Page")
	void SetAutoResizeToWidget(bool bEnabled);

	/** 设置是否将UE场景的键盘事件转发给CEF（撤销重做等场景） */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Input")
	void SetForwardUEKeyEvents(bool bEnabled);

	/** 从平台层直接获取光标屏幕坐标（绕过Slate/CEF事件管道，零延迟） */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Input")
	bool GetRawPlatformCursorPos(FVector2D& OutScreenPos) const;

	/** 将屏幕绝对坐标转为视口相对坐标并反投影到世界空间，自动适配PIE/窗口/全屏 */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Input")
	bool DeprojectCursorToWorld(FVector2D ScreenPos, FVector& OutWorldPos, FVector& OutWorldDir) const;

	/** Get the current CEF browser view size. */
	UFUNCTION(BlueprintPure, Category = "WebNative|Page")
	FIntPoint GetViewSize() const;

	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

private:
	/** 内部实现：对外统一使用 SendMessageToJS，此长名仅供类内转发 */
	void SendMessageToJavaScript(const FString& FunctionName, const FString& MessageBody);
	void HandleSlateMessage(const FString& FunctionName, const FString& MessageBody);
	void HandleSlateLoadStateChanged(bool bIsLoading, bool bCanGoBack, bool bCanGoForward);
	void HandleSlateUrlChanged(const FString& URL);
	void HandleSlateBeforePopup(const FString& TargetURL, const FString& TargetFrameName);
	void HandleSlateLoadEnd(const FString& URL, int32 HttpStatusCode);

	TSharedPtr<IWebNativeBrowserView> WebView;
	FString LastAppliedInitialURL;
};
