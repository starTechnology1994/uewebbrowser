// Copyright (c) 2026 StarTechnology. All rights reserved.

#include "SWebNativeFileDialog.h"

#include "Framework/Application/SlateApplication.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SWindow.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/STableRow.h"

namespace
{
FString GetDialogAcceptLabel(const EWebNativeFileDialogMode Mode)
{
	switch (Mode)
	{
	case EWebNativeFileDialogMode::OpenDirectory:
		return TEXT("Select Folder");
	case EWebNativeFileDialogMode::SaveFile:
		return TEXT("Save");
	default:
		return TEXT("Open");
	}
}
}

void SWebNativeFileDialog::Construct(const FArguments& InArgs)
{
	Request = InArgs._Request;
	OwnerWindow = InArgs._OwnerWindow;

	for (FString& Extension : Request.AllowedExtensions)
	{
		Extension.TrimStartAndEndInline();
		Extension.RemoveFromStart(TEXT("*."));
		Extension.RemoveFromStart(TEXT("."));
		Extension = Extension.ToLower();
	}
	Request.AllowedExtensions.RemoveAll([](const FString& Extension)
	{
		return Extension.IsEmpty() || Extension == TEXT("*");
	});

	FString InitialPath = Request.DefaultPath;
	if (InitialPath.IsEmpty())
	{
		InitialPath = FPlatformProcess::UserHomeDir();
	}
	InitialPath = NormalizeAbsolutePath(InitialPath);
	if (!IFileManager::Get().DirectoryExists(*InitialPath))
	{
		InitialPath = NormalizeAbsolutePath(FPaths::ProjectDir());
	}
	CurrentPath = InitialPath;

	ChildSlot
	[
		SNew(SBorder)
		.Padding(12.0f)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0.0f, 0.0f, 6.0f, 0.0f)
				[
					SNew(SButton)
					.Text(FText::FromString(TEXT("Up")))
					.ToolTipText(FText::FromString(TEXT("Go to the parent directory")))
					.OnClicked(this, &SWebNativeFileDialog::HandleUp)
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0.0f, 0.0f, 6.0f, 0.0f)
				[
					SNew(SButton)
					.Text(FText::FromString(TEXT("Home")))
					.OnClicked(this, &SWebNativeFileDialog::HandleHome)
				]

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SAssignNew(PathTextBox, SEditableTextBox)
					.Text(FText::FromString(CurrentPath))
					.SelectAllTextWhenFocused(true)
					.OnTextCommitted(this, &SWebNativeFileDialog::HandlePathCommitted)
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(6.0f, 0.0f, 0.0f, 0.0f)
				[
					SNew(SButton)
					.Text(FText::FromString(TEXT("Refresh")))
					.OnClicked(this, &SWebNativeFileDialog::HandleRefresh)
				]
			]

			+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			.Padding(0.0f, 10.0f)
			[
				SNew(SBorder)
				.Padding(2.0f)
				[
					SAssignNew(ListView, SListView<FEntryPtr>)
					.ListItemsSource(&Entries)
					.SelectionMode(
						Request.Mode == EWebNativeFileDialogMode::OpenMultiple
							? ESelectionMode::Multi
							: ESelectionMode::Single)
					.OnGenerateRow(this, &SWebNativeFileDialog::GenerateRow)
					.OnSelectionChanged(this, &SWebNativeFileDialog::HandleSelectionChanged)
					.OnMouseButtonDoubleClick(this, &SWebNativeFileDialog::HandleDoubleClick)
				]
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SSeparator)
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 8.0f, 0.0f, 0.0f)
			[
				SNew(SHorizontalBox)
				.Visibility(this, &SWebNativeFileDialog::GetSaveFilenameVisibility)

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(0.0f, 0.0f, 8.0f, 0.0f)
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("File name")))
				]

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SAssignNew(FilenameTextBox, SEditableTextBox)
					.Text(FText::FromString(Request.DefaultFile))
					.SelectAllTextWhenFocused(true)
				]
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 8.0f, 0.0f, 0.0f)
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(this, &SWebNativeFileDialog::GetStatusText)
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(8.0f, 0.0f)
				[
					SNew(SButton)
					.Text(FText::FromString(GetDialogAcceptLabel(Request.Mode)))
					.IsEnabled(this, &SWebNativeFileDialog::CanAccept)
					.OnClicked(this, &SWebNativeFileDialog::HandleAccept)
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SButton)
					.Text(FText::FromString(TEXT("Cancel")))
					.OnClicked(this, &SWebNativeFileDialog::HandleCancel)
				]
			]
		]
	];

	RefreshEntries();
}

FString SWebNativeFileDialog::NormalizeAbsolutePath(const FString& Path)
{
	FString Result = Path;
	Result.TrimStartAndEndInline();
	if (Result.IsEmpty())
	{
		return Result;
	}
	Result = FPaths::ConvertRelativePathToFull(Result);
	FPaths::NormalizeFilename(Result);
	FPaths::CollapseRelativeDirectories(Result);
	if (Result.Len() > 1)
	{
		Result.RemoveFromEnd(TEXT("/"));
	}
	return Result;
}

FString SWebNativeFileDialog::FormatFileSize(const int64 Bytes)
{
	if (Bytes < 1024)
	{
		return FString::Printf(TEXT("%lld B"), Bytes);
	}
	if (Bytes < 1024ll * 1024ll)
	{
		return FString::Printf(TEXT("%.1f KB"), static_cast<double>(Bytes) / 1024.0);
	}
	if (Bytes < 1024ll * 1024ll * 1024ll)
	{
		return FString::Printf(TEXT("%.1f MB"), static_cast<double>(Bytes) / (1024.0 * 1024.0));
	}
	return FString::Printf(TEXT("%.1f GB"), static_cast<double>(Bytes) / (1024.0 * 1024.0 * 1024.0));
}

void SWebNativeFileDialog::NavigateTo(const FString& Directory)
{
	const FString Normalized = NormalizeAbsolutePath(Directory);
	if (!IFileManager::Get().DirectoryExists(*Normalized))
	{
		Status = FString::Printf(TEXT("Directory not found: %s"), *Normalized);
		return;
	}

	CurrentPath = Normalized;
	Status.Reset();
	PendingOverwritePath.Reset();
	if (PathTextBox.IsValid())
	{
		PathTextBox->SetText(FText::FromString(CurrentPath));
	}
	if (ListView.IsValid())
	{
		ListView->ClearSelection();
	}
	RefreshEntries();
}

void SWebNativeFileDialog::RefreshEntries()
{
	Entries.Reset();

	TArray<FString> Directories;
	TArray<FString> Files;
	const FString Wildcard = FPaths::Combine(CurrentPath, TEXT("*"));
	IFileManager::Get().FindFiles(Directories, *Wildcard, false, true);
	IFileManager::Get().FindFiles(Files, *Wildcard, true, false);

	Directories.Sort([](const FString& A, const FString& B)
	{
		return A.Compare(B, ESearchCase::IgnoreCase) < 0;
	});
	Files.Sort([](const FString& A, const FString& B)
	{
		return A.Compare(B, ESearchCase::IgnoreCase) < 0;
	});

	for (const FString& Directory : Directories)
	{
		if (Directory == TEXT(".") || Directory == TEXT(".."))
		{
			continue;
		}
		FEntryPtr Entry = MakeShared<FWebNativeFileDialogEntry>();
		Entry->Name = Directory;
		Entry->FullPath = NormalizeAbsolutePath(FPaths::Combine(CurrentPath, Directory));
		Entry->bDirectory = true;
		Entries.Add(MoveTemp(Entry));
	}

	if (Request.Mode != EWebNativeFileDialogMode::OpenDirectory)
	{
		for (const FString& File : Files)
		{
			if (!IsAllowedFile(File))
			{
				continue;
			}
			FEntryPtr Entry = MakeShared<FWebNativeFileDialogEntry>();
			Entry->Name = File;
			Entry->FullPath = NormalizeAbsolutePath(FPaths::Combine(CurrentPath, File));
			Entry->Size = IFileManager::Get().FileSize(*Entry->FullPath);
			Entries.Add(MoveTemp(Entry));
		}
	}

	if (ListView.IsValid())
	{
		ListView->RequestListRefresh();
	}
	Status = FString::Printf(TEXT("%d item(s)"), Entries.Num());
}

bool SWebNativeFileDialog::IsAllowedFile(const FString& Filename) const
{
	if (Request.AllowedExtensions.Num() == 0)
	{
		return true;
	}
	const FString Extension = FPaths::GetExtension(Filename, false).ToLower();
	return Request.AllowedExtensions.Contains(Extension);
}

bool SWebNativeFileDialog::CanAccept() const
{
	if (Request.Mode == EWebNativeFileDialogMode::OpenDirectory)
	{
		return !CurrentPath.IsEmpty();
	}
	if (Request.Mode == EWebNativeFileDialogMode::SaveFile)
	{
		return FilenameTextBox.IsValid() &&
			!FilenameTextBox->GetText().ToString().TrimStartAndEnd().IsEmpty();
	}
	if (!ListView.IsValid())
	{
		return false;
	}
	for (const FEntryPtr& Entry : ListView->GetSelectedItems())
	{
		if (Entry.IsValid() && !Entry->bDirectory)
		{
			return true;
		}
	}
	return false;
}

void SWebNativeFileDialog::CloseWindow()
{
	if (const TSharedPtr<SWindow> Window = OwnerWindow.Pin())
	{
		Window->RequestDestroyWindow();
	}
}

TSharedRef<ITableRow> SWebNativeFileDialog::GenerateRow(
	FEntryPtr Entry,
	const TSharedRef<STableViewBase>& OwnerTable)
{
	const FString TypeText = Entry.IsValid() && Entry->bDirectory ? TEXT("[DIR]") : TEXT("[FILE]");
	const FString NameText = Entry.IsValid() ? Entry->Name : FString();
	const FString SizeText =
		Entry.IsValid() && !Entry->bDirectory && Entry->Size >= 0
			? FormatFileSize(Entry->Size)
			: FString();

	return SNew(STableRow<FEntryPtr>, OwnerTable)
		.Padding(FMargin(4.0f, 3.0f))
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0.0f, 0.0f, 10.0f, 0.0f)
			[
				SNew(STextBlock)
					.Text(FText::FromString(TypeText))
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(STextBlock)
					.Text(FText::FromString(NameText))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
					.Text(FText::FromString(SizeText))
			]
		];
}

void SWebNativeFileDialog::HandleSelectionChanged(FEntryPtr Entry, ESelectInfo::Type SelectInfo)
{
	if (Request.Mode == EWebNativeFileDialogMode::SaveFile &&
		Entry.IsValid() && !Entry->bDirectory && FilenameTextBox.IsValid())
	{
		PendingOverwritePath.Reset();
		FilenameTextBox->SetText(FText::FromString(Entry->Name));
	}
}

void SWebNativeFileDialog::HandleDoubleClick(FEntryPtr Entry)
{
	if (!Entry.IsValid())
	{
		return;
	}
	if (Entry->bDirectory)
	{
		NavigateTo(Entry->FullPath);
		return;
	}
	if (Request.Mode != EWebNativeFileDialogMode::SaveFile)
	{
		HandleAccept();
	}
}

void SWebNativeFileDialog::HandlePathCommitted(const FText& Text, ETextCommit::Type CommitType)
{
	if (CommitType == ETextCommit::OnEnter)
	{
		NavigateTo(Text.ToString());
	}
}

FReply SWebNativeFileDialog::HandleUp()
{
	FString Parent = FPaths::GetPath(CurrentPath);
	if (Parent.IsEmpty())
	{
		Parent = TEXT("/");
	}
	NavigateTo(Parent);
	return FReply::Handled();
}

FReply SWebNativeFileDialog::HandleHome()
{
	NavigateTo(FPlatformProcess::UserHomeDir());
	return FReply::Handled();
}

FReply SWebNativeFileDialog::HandleRefresh()
{
	RefreshEntries();
	return FReply::Handled();
}

FReply SWebNativeFileDialog::HandleAccept()
{
	if (!CanAccept())
	{
		return FReply::Handled();
	}

	SelectedPaths.Reset();
	if (Request.Mode == EWebNativeFileDialogMode::OpenDirectory)
	{
		FString SelectedDirectory = CurrentPath;
		if (ListView.IsValid())
		{
			for (const FEntryPtr& Entry : ListView->GetSelectedItems())
			{
				if (Entry.IsValid() && Entry->bDirectory)
				{
					SelectedDirectory = Entry->FullPath;
					break;
				}
			}
		}
		SelectedPaths.Add(NormalizeAbsolutePath(SelectedDirectory));
	}
	else if (Request.Mode == EWebNativeFileDialogMode::SaveFile)
	{
		FString Filename = FilenameTextBox->GetText().ToString().TrimStartAndEnd();
		Filename = FPaths::GetCleanFilename(Filename);
		if (Filename.IsEmpty() || Filename == TEXT(".") || Filename == TEXT(".."))
		{
			Status = TEXT("Enter a valid file name.");
			return FReply::Handled();
		}
		if (FPaths::GetExtension(Filename, false).IsEmpty() &&
			Request.AllowedExtensions.Num() == 1)
		{
			Filename += TEXT(".") + Request.AllowedExtensions[0];
		}
		const FString SavePath =
			NormalizeAbsolutePath(FPaths::Combine(CurrentPath, Filename));
		if (IFileManager::Get().FileExists(*SavePath) &&
			PendingOverwritePath != SavePath)
		{
			PendingOverwritePath = SavePath;
			Status = TEXT("File already exists. Click Save again to overwrite it.");
			return FReply::Handled();
		}
		SelectedPaths.Add(SavePath);
	}
	else
	{
		const TArray<FEntryPtr> SelectedItems = ListView->GetSelectedItems();
		// Preserve visible list order for deterministic multi-selection results.
		for (const FEntryPtr& Entry : Entries)
		{
			if (Entry.IsValid() && !Entry->bDirectory && SelectedItems.Contains(Entry))
			{
				SelectedPaths.Add(Entry->FullPath);
				if (Request.Mode == EWebNativeFileDialogMode::OpenFile)
				{
					break;
				}
			}
		}
	}

	if (SelectedPaths.Num() == 0)
	{
		Status = TEXT("Select a valid file or directory.");
		return FReply::Handled();
	}

	bAccepted = true;
	CloseWindow();
	return FReply::Handled();
}

FReply SWebNativeFileDialog::HandleCancel()
{
	bAccepted = false;
	SelectedPaths.Reset();
	CloseWindow();
	return FReply::Handled();
}

FText SWebNativeFileDialog::GetStatusText() const
{
	return FText::FromString(Status);
}

EVisibility SWebNativeFileDialog::GetSaveFilenameVisibility() const
{
	return Request.Mode == EWebNativeFileDialogMode::SaveFile
		? EVisibility::Visible
		: EVisibility::Collapsed;
}
