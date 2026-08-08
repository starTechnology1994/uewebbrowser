// Copyright (c) 2026 StarTechnology. All rights reserved.

#include "IWebNativeBrowserFileDialog.h"

#include "Framework/Application/SlateApplication.h"
#include "SWebNativeFileDialog.h"
#include "Widgets/SWindow.h"

class FWebNativeBrowserFileDialogModule final : public IWebNativeBrowserFileDialogModule
{
public:
	virtual bool ShowDialog(
		const FWebNativeFileDialogRequest& Request,
		TArray<FString>& OutPaths) override
	{
		check(IsInGameThread());
		OutPaths.Reset();

		if (!FSlateApplication::IsInitialized() ||
			!FSlateApplication::Get().CanAddModalWindow())
		{
			return false;
		}

		FString Title = Request.Title;
		if (Title.IsEmpty())
		{
			switch (Request.Mode)
			{
			case EWebNativeFileDialogMode::OpenDirectory:
				Title = TEXT("Select Folder");
				break;
			case EWebNativeFileDialogMode::SaveFile:
				Title = TEXT("Save File");
				break;
			default:
				Title = TEXT("Open File");
				break;
			}
		}
		const FText WindowTitle = FText::FromString(Title);
		const TSharedRef<SWindow> Window =
			SNew(SWindow)
			.Title(WindowTitle)
			.ClientSize(FVector2D(820.0f, 560.0f))
			.SupportsMinimize(false)
			.SupportsMaximize(false)
			.SizingRule(ESizingRule::UserSized);

		TSharedPtr<SWebNativeFileDialog> Dialog;
		Window->SetContent(
			SAssignNew(Dialog, SWebNativeFileDialog)
			.Request(Request)
			.OwnerWindow(Window));

		const TSharedPtr<SWindow> ParentWindow =
			FSlateApplication::Get().GetActiveTopLevelWindow();
		FSlateApplication::Get().AddModalWindow(Window, ParentWindow);

		if (!Dialog.IsValid() || !Dialog->WasAccepted())
		{
			return false;
		}

		OutPaths = Dialog->GetSelectedPaths();
		return OutPaths.Num() > 0;
	}
};

IMPLEMENT_MODULE(FWebNativeBrowserFileDialogModule, WebNativeBrowserFileDialog)
