// Copyright (c) 2026 StarTechnology. All rights reserved.

#include "WebNativeBrowserWidget.h"

#include "Engine/GameViewportClient.h"
#include "Engine/World.h"
#include "Framework/Application/SlateApplication.h"
#include "IWebNativeBrowserCore.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/Paths.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SViewport.h"

UWebNativeBrowserWidget::UWebNativeBrowserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetVisibility(ESlateVisibility::Visible);
}

void UWebNativeBrowserWidget::LoadURL(const FString& URL)
{
	InitialURL = URL;
	LastAppliedInitialURL = URL;
	if (WebView.IsValid())
	{
		WebView->LoadURL(URL);
	}
}

void UWebNativeBrowserWidget::GoBack()
{
	if (WebView.IsValid())
	{
		WebView->GoBack();
	}
}

void UWebNativeBrowserWidget::GoForward()
{
	if (WebView.IsValid())
	{
		WebView->GoForward();
	}
}

void UWebNativeBrowserWidget::Reload(bool bIgnoreCache)
{
	if (WebView.IsValid())
	{
		WebView->Reload(bIgnoreCache);
	}
}

void UWebNativeBrowserWidget::ExecuteJavaScript(const FString& Script)
{
	if (WebView.IsValid())
	{
		WebView->ExecuteJavaScript(Script);
	}
}

void UWebNativeBrowserWidget::SendMessageToJavaScript(const FString& FunctionName, const FString& MessageBody)
{
	if (WebView.IsValid())
	{
		WebView->SendMessageToJavaScript(FunctionName, MessageBody);
	}
}

void UWebNativeBrowserWidget::SendMessageToJS(const FString& FunctionName, const FString& MessageBody)
{
	SendMessageToJavaScript(FunctionName, MessageBody);
}

void UWebNativeBrowserWidget::FlushMessagesToJS()
{
	if (WebView.IsValid())
	{
		WebView->FlushMessagesToJS();
	}
}

void UWebNativeBrowserWidget::SetFocusToGameViewport()
{
	// 将焦点切回UE游戏场景前, 先给CEF注入清理事件清空网页按键状态
	if (WebView.IsValid())
	{
		// 与 GResetInputJS 保持一致: 直接调clearAllInputState + dispatch blur/focusout
		WebView->ExecuteJavaScript(TEXT(
			"if(window.clearAllInputState)window.clearAllInputState();"
			"window.dispatchEvent(new Event('blur'));"
			"document.dispatchEvent(new Event('focusout'));"
		));
	}

	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().ReleaseAllPointerCapture();
		FSlateApplication::Get().SetAllUserFocusToGameViewport(EFocusCause::SetDirectly);
	}
}

void UWebNativeBrowserWidget::ShowDevTools()
{
	if (WebView.IsValid())
	{
		WebView->ShowDevTools();
	}
}

void UWebNativeBrowserWidget::CloseDevTools()
{
	if (WebView.IsValid())
	{
		WebView->CloseDevTools();
	}
}

void UWebNativeBrowserWidget::ToggleDevTools()
{
	if (WebView.IsValid())
	{
		WebView->ToggleDevTools();
	}
}

void UWebNativeBrowserWidget::SetViewResolution(FIntPoint NewSize)
{
	ViewSize.X = FMath::Max(1, NewSize.X);
	ViewSize.Y = FMath::Max(1, NewSize.Y);
	if (WebView.IsValid())
	{
		WebView->SetViewSize(ViewSize);
	}
}

void UWebNativeBrowserWidget::SetAutoResizeToWidget(bool bEnabled)
{
	bAutoResizeToWidget = bEnabled;
	if (WebView.IsValid())
	{
		WebView->SetAutoResizeToWidget(bAutoResizeToWidget);
	}
}

void UWebNativeBrowserWidget::SetForwardUEKeyEvents(bool bEnabled)
{
	bForwardUEKeyEvents = bEnabled;
	if (WebView.IsValid())
	{
		WebView->SetForwardUEKeyEvents(bEnabled);
	}
}

bool UWebNativeBrowserWidget::GetRawPlatformCursorPos(FVector2D& OutScreenPos) const
{
	// Slate 层直接读取平台光标,绕过 CEF 事件管道
	if (FSlateApplication::IsInitialized())
	{
		OutScreenPos = FSlateApplication::Get().GetCursorPos();
		return true;
	}
	return false;
}

bool UWebNativeBrowserWidget::DeprojectCursorToWorld(FVector2D ScreenPos, FVector& OutWorldPos, FVector& OutWorldDir) const
{
	APlayerController* PC = GetOwningPlayer();
	if (!PC)
	{
		return false;
	}

	// 屏幕绝对坐标 → 视口相对坐标（修复 PIE/窗口模式偏移）
	UGameViewportClient* VP = GetWorld()->GetGameViewport();
	if (VP)
	{
		TSharedPtr<SViewport> VPWidget = VP->GetGameViewportWidget();
		if (VPWidget.IsValid())
		{
			const FVector2D ViewportScreenPos = VPWidget->GetCachedGeometry().GetAbsolutePosition();
			ScreenPos -= ViewportScreenPos;
		}
	}

	return UGameplayStatics::DeprojectScreenToWorld(PC, ScreenPos, OutWorldPos, OutWorldDir);
}

FIntPoint UWebNativeBrowserWidget::GetViewSize() const
{
	return ViewSize;
}

void UWebNativeBrowserWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (WebView.IsValid())
	{
		const FWebNativeBrowserRuntimeOptions& RuntimeOptions = IWebNativeBrowserCoreModule::Get().GetRuntimeOptions();

		if (InitialURL != LastAppliedInitialURL)
		{
			LastAppliedInitialURL = InitialURL;
			WebView->LoadURL(InitialURL);
		}

		if (!bAutoResizeToWidget)
		{
			WebView->SetViewSize(ViewSize);
		}
		WebView->SetRenderOptions(bUseGpuAcceleratedRendering && !RuntimeOptions.bOffGpu, bAllowCpuRenderFallback);
		WebView->SetAcceptsInput(bAcceptsInput);
		WebView->SetAutoFocusOnMouseDown(bAutoFocusOnMouseDown);
		WebView->SetMouseTransparency(bEnableMouseTransparency, MouseTransparencyAlphaThreshold, MouseTransparencyMaskBlockSize);
		WebView->SetAutoResizeToWidget(bAutoResizeToWidget);
		WebView->SetMessageDispatchBudgetPerFrame(MessageDispatchBudgetPerFrame);
		WebView->SetForwardUEKeyEvents(bForwardUEKeyEvents);
		WebView->SetOnMessage(BIND_UOBJECT_DELEGATE(FWebNativeBrowserNativeMessageDelegate, HandleSlateMessage));
		WebView->SetOnLoadStateChanged(BIND_UOBJECT_DELEGATE(FWebNativeBrowserLoadStateDelegate, HandleSlateLoadStateChanged));
		WebView->SetOnUrlChanged(BIND_UOBJECT_DELEGATE(FWebNativeBrowserUrlChangedDelegate, HandleSlateUrlChanged));
		WebView->SetOnBeforePopup(BIND_UOBJECT_DELEGATE(FWebNativeBrowserBeforePopupDelegate, HandleSlateBeforePopup));
		WebView->SetOnLoadEnd(BIND_UOBJECT_DELEGATE(FWebNativeBrowserLoadEndDelegate, HandleSlateLoadEnd));
	}
}

TSharedRef<SWidget> UWebNativeBrowserWidget::RebuildWidget()
{
	LastAppliedInitialURL = InitialURL;

	if (IsDesignTime())
	{
		return SNew(SBox)
			.WidthOverride(ViewSize.X)
			.HeightOverride(ViewSize.Y);
	}

	IWebNativeBrowserCoreModule& CoreModule = IWebNativeBrowserCoreModule::Get();
	const FWebNativeBrowserRuntimeOptions& RuntimeOptions = CoreModule.GetRuntimeOptions();

	FWebNativeBrowserViewArgs Args;
	Args.InitialURL = InitialURL;
	Args.ViewSize = ViewSize;
	Args.FrameRate = FrameRate;
	Args.bUseGpuAcceleratedRendering = bUseGpuAcceleratedRendering && !RuntimeOptions.bOffGpu;
	Args.bAllowCpuRenderFallback = bAllowCpuRenderFallback;
	Args.bShowCefPerformanceMonitor = RuntimeOptions.bShowCefPerformanceMonitor;
	Args.bShowDownloadNotification = RuntimeOptions.bShowDownloadNotification;
	Args.bAcceptsInput = bAcceptsInput;
	Args.bAutoFocusOnMouseDown = bAutoFocusOnMouseDown;
	Args.bEnableMouseTransparency = bEnableMouseTransparency;
	Args.MouseTransparencyAlphaThreshold = MouseTransparencyAlphaThreshold;
	Args.MouseTransparencyMaskBlockSize = MouseTransparencyMaskBlockSize;
	Args.bAutoResizeToWidget = bAutoResizeToWidget;
	Args.bKeyboardF5 = RuntimeOptions.bKeyboardF5;
	Args.bCtrlScale = RuntimeOptions.bCtrlScale;
	Args.MessageDispatchBudgetPerFrame = MessageDispatchBudgetPerFrame;
	Args.OnMessage = BIND_UOBJECT_DELEGATE(FWebNativeBrowserNativeMessageDelegate, HandleSlateMessage);
	Args.OnLoadStateChanged = BIND_UOBJECT_DELEGATE(FWebNativeBrowserLoadStateDelegate, HandleSlateLoadStateChanged);
	Args.OnUrlChanged = BIND_UOBJECT_DELEGATE(FWebNativeBrowserUrlChangedDelegate, HandleSlateUrlChanged);
	Args.OnBeforePopup = BIND_UOBJECT_DELEGATE(FWebNativeBrowserBeforePopupDelegate, HandleSlateBeforePopup);
	Args.OnLoadEnd = BIND_UOBJECT_DELEGATE(FWebNativeBrowserLoadEndDelegate, HandleSlateLoadEnd);

	WebView = CoreModule.CreateBrowserView(Args);
	return WebView->GetSlateWidget();
}

void UWebNativeBrowserWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	if (WebView.IsValid())
	{
		WebView->CloseBrowser();
		WebView.Reset();
	}
}

#if WITH_EDITOR
const FText UWebNativeBrowserWidget::GetPaletteCategory()
{
	return FText::FromString(TEXT("Web View"));
}
#endif

void UWebNativeBrowserWidget::HandleSlateMessage(const FString& FunctionName, const FString& MessageBody)
{
	OnMessageReceived.Broadcast(FunctionName, MessageBody);
}

void UWebNativeBrowserWidget::HandleSlateLoadStateChanged(bool bIsLoading, bool bCanGoBack, bool bCanGoForward)
{
	OnLoadStateChanged.Broadcast(bIsLoading, bCanGoBack, bCanGoForward);
}

void UWebNativeBrowserWidget::HandleSlateUrlChanged(const FString& URL)
{
	OnUrlChanged.Broadcast(URL);
}

void UWebNativeBrowserWidget::HandleSlateBeforePopup(const FString& TargetURL, const FString& TargetFrameName)
{
	OnBeforePopup.Broadcast(TargetURL, TargetFrameName);
}

void UWebNativeBrowserWidget::HandleSlateLoadEnd(const FString& URL, int32 HttpStatusCode)
{
	OnLoadEnd.Broadcast(URL, HttpStatusCode);
}
