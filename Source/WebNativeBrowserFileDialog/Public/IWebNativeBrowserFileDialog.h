// Copyright (c) 2026 StarTechnology. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

enum class EWebNativeFileDialogMode : uint8
{
	OpenFile,
	OpenMultiple,
	OpenDirectory,
	SaveFile
};

struct FWebNativeFileDialogRequest
{
	EWebNativeFileDialogMode Mode = EWebNativeFileDialogMode::OpenFile;
	FString Title;
	FString DefaultPath;
	FString DefaultFile;

	// Lower-case extensions without a leading dot (for example: "png").
	// Empty means all files.
	TArray<FString> AllowedExtensions;
};

class WEBNATIVEBROWSERFILEDIALOG_API IWebNativeBrowserFileDialogModule : public IModuleInterface
{
public:
	static IWebNativeBrowserFileDialogModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IWebNativeBrowserFileDialogModule>(
			TEXT("WebNativeBrowserFileDialog"));
	}

	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded(TEXT("WebNativeBrowserFileDialog"));
	}

	// Must be called on the GameThread with Slate initialized. This method runs
	// a modal Slate window and returns after the user accepts or cancels.
	virtual bool ShowDialog(
		const FWebNativeFileDialogRequest& Request,
		TArray<FString>& OutPaths) = 0;
};
