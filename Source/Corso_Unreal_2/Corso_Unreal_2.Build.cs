// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Corso_Unreal_2 : ModuleRules
{
	public Corso_Unreal_2(ReadOnlyTargetRules Target) : base(Target)
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
			"Corso_Unreal_2",
			"Corso_Unreal_2/Variant_Horror",
			"Corso_Unreal_2/Variant_Horror/UI",
			"Corso_Unreal_2/Variant_Shooter",
			"Corso_Unreal_2/Variant_Shooter/AI",
			"Corso_Unreal_2/Variant_Shooter/UI",
			"Corso_Unreal_2/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
