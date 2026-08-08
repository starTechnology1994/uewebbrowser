// Copyright (c) 2026 StarTechnology. All rights reserved.

using System.IO;
using UnrealBuildTool;

public class WebNativeBrowserVulkanBootstrap : ModuleRules
{
	public WebNativeBrowserVulkanBootstrap(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.Add("Core");
		PrivateDependencyModuleNames.Add("Projects");

		if (Target.Platform == UnrealTargetPlatform.Linux || Target.Platform == UnrealTargetPlatform.LinuxArm64)
		{
			PrivateDependencyModuleNames.Add("RHI");
			PrivateDependencyModuleNames.Add("VulkanRHI");

			// VulkanRHI does not propagate Vulkan ThirdParty include paths to
			// dependent modules when cross-compiling for Linux (all UE5 versions).
			string VulkanIncludeBase = Path.Combine(EngineDirectory, "Source", "ThirdParty", "Vulkan", "Include");
			PublicSystemIncludePaths.Add(VulkanIncludeBase);
			PublicSystemIncludePaths.Add(Path.Combine(VulkanIncludeBase, "vulkan"));
		}
	}
}
