// Copyright (c) 2026 StarTechnology. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "IWebNativeBrowserCore.h"
#include "Misc/OutputDevice.h"

class FWebNativeBrowserCoreModule final : public IWebNativeBrowserCoreModule
{
public:
	static FWebNativeBrowserCoreModule& Get();

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual TSharedRef<IWebNativeBrowserView> CreateBrowserView(const FWebNativeBrowserViewArgs& Args) override;

	bool EnsureCefInitialized();
	bool IsCefInitialized() const { return bCefInitialized; }
	FString GetCefRuntimeDir() const;
	FString GetCefHelperPath() const;
	bool IsUsingNativeHelper() const { return bUsingNativeHelper; }
	FWebNativeBrowserRuntimeOptions GetDefaultRuntimeOptions();
	float GetCefSubprocessMemoryMB() const;
	void ApplyRuntimeOptions(const FWebNativeBrowserRuntimeOptions& InOptions);
	virtual const FWebNativeBrowserRuntimeOptions& GetRuntimeOptions() override;
	int32 GetRemoteDebuggingPort() const { return ActualRemoteDebuggingPort; }

private:
	void EnsureMultiOpenInstanceId();
	void LoadRuntimeOptionsFromConfig();
	void ShutdownCefRuntime();
	void KillResidualCefSubprocesses() const;
	void CleanupInstanceDirectories();
	void LaunchDeferredInstanceCleanup() const;
	bool DeleteInstanceDirectoryWithRetry(const FString& Directory, const TCHAR* DirectoryType) const;

	FWebNativeBrowserRuntimeOptions RuntimeOptions;
	bool bCefInitialized = false;
	bool bUsingNativeHelper = false;
	bool bRuntimeOptionsLoaded = false;
	bool bCefShutdownRequested = false;
	FString ActiveSubprocessExecutableName;
	FDelegateHandle PreExitHandle;
	FDelegateHandle AppActivationHandle;
	void* LibCefHandle = nullptr;
	FOutputDevice* CefLogDevice = nullptr;
	int32 ActualRemoteDebuggingPort = 19223;
	FString MultiOpenInstanceId;
	bool bInstanceIdResolved = false;
};
