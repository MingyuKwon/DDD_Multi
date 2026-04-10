// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DDD : ModuleRules
{
	public DDD(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"DDD",
			"DDD/DataStruct",
			"DDD/Variant_Platforming",
			"DDD/Variant_Platforming/Animation",
			"DDD/Variant_Combat",
			"DDD/Variant_Combat/AI",
			"DDD/Variant_Combat/Animation",
			"DDD/Variant_Combat/Gameplay",
			"DDD/Variant_Combat/Interfaces",
			"DDD/Variant_Combat/UI",
			"DDD/Variant_SideScrolling",
			"DDD/Variant_SideScrolling/AI",
			"DDD/Variant_SideScrolling/Gameplay",
			"DDD/Variant_SideScrolling/Interfaces",
			"DDD/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
