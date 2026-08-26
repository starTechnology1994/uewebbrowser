// Copyright (c) 2026 StarTechnology. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "Modules/ModuleManager.h"
#include "Widgets/SWidget.h"

class APlayerController;

DECLARE_DELEGATE_TwoParams(FWebNativeBrowserNativeMessageDelegate, const FString& /*FunctionName*/, const FString& /*MessageBody*/);
DECLARE_DELEGATE_ThreeParams(FWebNativeBrowserLoadStateDelegate, bool /*bIsLoading*/, bool /*bCanGoBack*/, bool /*bCanGoForward*/);
DECLARE_DELEGATE_OneParam(FWebNativeBrowserUrlChangedDelegate, const FString& /*URL*/);
DECLARE_DELEGATE_TwoParams(FWebNativeBrowserBeforePopupDelegate, const FString& /*TargetURL*/, const FString& /*TargetFrameName*/);
DECLARE_DELEGATE_TwoParams(FWebNativeBrowserLoadEndDelegate, const FString& /*URL*/, int32 /*HttpStatusCode*/);

struct FWebNativeBrowserRuntimeOptions
{
	bool bClearCache = false;
	bool bClearLog = true;
	bool bOffGpu = false;
	bool bTouch = true;
	bool bKeyboardF5 = false;
	bool bCtrlScale = false;
#if PLATFORM_LINUX
	bool bLinuxSingleProcess = false;
#endif
	FString MediaPermissionPolicy = TEXT("allow");
	FString PermissionPromptPolicy = TEXT("allow");
	bool bAllowMicrophone = true;
	bool bAllowCamera = true;
	bool bAllowDesktopCapture = true;
	bool bAllowClipboard = true;
	bool bAllowGeolocation = true;
	bool bAllowNotifications = true;
	bool bAllowLocalNetworkAccess = true;
	bool bAllowFileSystemAccess = true;
	bool bAllowPointerLock = true;
	bool bAllowKeyboardLock = true;
	bool bAllowStorageAccess = true;
	bool bAllowProtectedMedia = true;
	bool bAllowLocalFonts = true;
	bool bAllowMidiSysex = false;
	bool bAllowMultipleDownloads = true;
	bool bAllowWindowManagement = true;
	bool bAllowExtendedReality = false;
	bool bAllowOtherPermissionPrompts = false;
	bool bShowCefPerformanceMonitor = false;
	bool bShowDownloadNotification = true;
	bool bGpuSharedMutexPerAdapter = true;

	// true  = multi-open mode:  each instance gets an independent cache dir;
	//         cookies / localStorage / cache are NOT shared and NOT reused
	//         across launches.  Safe for concurrent multi-process use.
	// false = single-instance mode: shared cache dir (WebNativeCache) and
	//         shared log dir (cef); cache IS persistent across launches.
	//         MUST NOT run more than one UE process at the same time.
	bool bMultiOpen = false;
	int32 RemoteDebuggingPortMin = 19223;
	int32 RemoteDebuggingPortMax = 19262;
	FString CefCoreArgs = TEXT("disable-web-security no-proxy-server allow-file-access-from-files allow-universal-access-from-files allow-running-insecure-content allow-insecure-localhost");
	FString CefArgs;
};

struct FWebNativeBrowserViewArgs
{
	FString InitialURL = TEXT("https://www.bilibili.com");
	FIntPoint ViewSize = FIntPoint(1280, 720);
	int32 FrameRate = 60;
	bool bUseGpuAcceleratedRendering = true;
	bool bAllowCpuRenderFallback = true;
	bool bAcceptsInput = true;
	bool bAutoFocusOnMouseDown = true;
	bool bEnableMouseTransparency = false;
	int32 MouseTransparencyAlphaThreshold = 0;
	int32 MouseTransparencyMaskBlockSize = 1;
	bool bAutoResizeToWidget = true;
	bool bKeyboardF5 = true;
	bool bCtrlScale = false;
	bool bTransparentBackground = true;
	int32 MessageDispatchBudgetPerFrame = 5000;
	bool bShowCefPerformanceMonitor = false;
	bool bShowDownloadNotification = true;
	FWebNativeBrowserNativeMessageDelegate OnMessage;
	FWebNativeBrowserLoadStateDelegate OnLoadStateChanged;
	FWebNativeBrowserUrlChangedDelegate OnUrlChanged;
	FWebNativeBrowserBeforePopupDelegate OnBeforePopup;
	FWebNativeBrowserLoadEndDelegate OnLoadEnd;
	bool bUse3DWidgetComponentMode = false;
};

class WEBNATIVEBROWSERCORE_API IWebNativeBrowserView
{
public:
	virtual ~IWebNativeBrowserView() = default;

	virtual TSharedRef<SWidget> GetSlateWidget() = 0;
	virtual void LoadURL(const FString& URL) = 0;
	virtual void GoBack() = 0;
	virtual void GoForward() = 0;
	virtual void Reload(bool bIgnoreCache) = 0;
	virtual void ExecuteJavaScript(const FString& Script) = 0;
	virtual void SendMessageToJavaScript(const FString& FunctionName, const FString& MessageBody) = 0;
	virtual void FlushMessagesToJS() = 0;
	virtual void ShowDevTools() = 0;
	virtual void CloseDevTools() = 0;
	virtual void ToggleDevTools() = 0;
	virtual void CloseBrowser() = 0;
	virtual void SetViewSize(FIntPoint InViewSize) = 0;
	virtual void SetRenderOptions(bool bUseGpuAcceleratedRendering, bool bAllowCpuRenderFallback) = 0;
	virtual void SetAcceptsInput(bool bAcceptsInput) = 0;
	virtual void SetAutoFocusOnMouseDown(bool bAutoFocusOnMouseDown) = 0;
	virtual void SetUse3DWidgetComponentMode(bool bEnabled) = 0;
	virtual void SetTransparentScenePrimitiveEvents(bool bEnabled, APlayerController* OwningPlayer) = 0;
	virtual void SetMouseTransparency(bool bEnableMouseTransparency, int32 AlphaThreshold, int32 MaskBlockSize) = 0;
	virtual void SetAutoResizeToWidget(bool bAutoResizeToWidget) = 0;
	virtual void SetMessageDispatchBudgetPerFrame(int32 MessageDispatchBudgetPerFrame) = 0;
	virtual void SetForwardUEKeyEvents(bool bForwardUEKeyEvents) = 0;
	virtual void SetOnMessage(FWebNativeBrowserNativeMessageDelegate OnMessage) = 0;
	virtual void SetOnLoadStateChanged(FWebNativeBrowserLoadStateDelegate OnLoadStateChanged) = 0;
	virtual void SetOnUrlChanged(FWebNativeBrowserUrlChangedDelegate OnUrlChanged) = 0;
	virtual void SetOnBeforePopup(FWebNativeBrowserBeforePopupDelegate OnBeforePopup) = 0;
	virtual void SetOnLoadEnd(FWebNativeBrowserLoadEndDelegate OnLoadEnd) = 0;
};

class WEBNATIVEBROWSERCORE_API IWebNativeBrowserCoreModule : public IModuleInterface
{
public:
	static IWebNativeBrowserCoreModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IWebNativeBrowserCoreModule>(TEXT("WebNativeBrowserCore"));
	}

	virtual const FWebNativeBrowserRuntimeOptions& GetRuntimeOptions() = 0;
	virtual TSharedRef<IWebNativeBrowserView> CreateBrowserView(const FWebNativeBrowserViewArgs& Args) = 0;
};
