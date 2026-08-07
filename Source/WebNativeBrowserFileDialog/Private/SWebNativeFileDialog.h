// Copyright (c) 2026 StarTechnology. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "IWebNativeBrowserFileDialog.h"
#include "Types/SlateEnums.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Views/SListView.h"

class SEditableTextBox;
class SWindow;

struct FWebNativeFileDialogEntry
{
	FString Name;
	FString FullPath;
	bool bDirectory = false;
	int64 Size = 0;
};

class SWebNativeFileDialog final : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SWebNativeFileDialog) {}
		SLATE_ARGUMENT(FWebNativeFileDialogRequest, Request)
		SLATE_ARGUMENT(TWeakPtr<SWindow>, OwnerWindow)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	bool WasAccepted() const { return bAccepted; }
	const TArray<FString>& GetSelectedPaths() const { return SelectedPaths; }

private:
	using FEntryPtr = TSharedPtr<FWebNativeFileDialogEntry>;

	static FString NormalizeAbsolutePath(const FString& Path);
	static FString FormatFileSize(int64 Bytes);

	void NavigateTo(const FString& Directory);
	void RefreshEntries();
	bool IsAllowedFile(const FString& Filename) const;
	bool CanAccept() const;
	void CloseWindow();

	TSharedRef<ITableRow> GenerateRow(
		FEntryPtr Entry,
		const TSharedRef<STableViewBase>& OwnerTable);
	void HandleSelectionChanged(FEntryPtr Entry, ESelectInfo::Type SelectInfo);
	void HandleDoubleClick(FEntryPtr Entry);
	void HandlePathCommitted(const FText& Text, ETextCommit::Type CommitType);

	FReply HandleUp();
	FReply HandleHome();
	FReply HandleRefresh();
	FReply HandleAccept();
	FReply HandleCancel();

	FText GetStatusText() const;
	EVisibility GetSaveFilenameVisibility() const;

	FWebNativeFileDialogRequest Request;
	TWeakPtr<SWindow> OwnerWindow;
	FString CurrentPath;
	FString Status;
	FString PendingOverwritePath;
	bool bAccepted = false;
	TArray<FString> SelectedPaths;
	TArray<FEntryPtr> Entries;

	TSharedPtr<SListView<FEntryPtr>> ListView;
	TSharedPtr<SEditableTextBox> PathTextBox;
	TSharedPtr<SEditableTextBox> FilenameTextBox;
};
