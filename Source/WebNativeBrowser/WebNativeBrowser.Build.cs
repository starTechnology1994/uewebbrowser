// Copyright (c) 2026 StarTechnology. All rights reserved.

using UnrealBuildTool;

public class WebNativeBrowser : ModuleRules
{
	public WebNativeBrowser(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"Slate",
			"SlateCore",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"ApplicationCore",
			"WebNativeBrowserCore"
		});
	}
}
