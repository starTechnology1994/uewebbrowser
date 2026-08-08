// Copyright (c) 2026 StarTechnology. All rights reserved.

using UnrealBuildTool;

public class WebNativeBrowserFileDialog : ModuleRules
{
	public WebNativeBrowserFileDialog(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bUseUnity = false;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core"
		});

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"ApplicationCore",
			"InputCore",
			"Slate",
			"SlateCore"
		});
	}
}
