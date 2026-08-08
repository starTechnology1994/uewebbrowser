// Copyright (c) 2026 StarTechnology. All rights reserved.

using UnrealBuildTool;

public class WebNativeBrowserEditor : ModuleRules
{
    public WebNativeBrowserEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "EditorSubsystem",
            "ToolMenus",
            "Slate",
            "SlateCore",
            "InputCore",
            "AssetRegistry",
            "RenderCore",
            "RHI",
        });
    }
}
