// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AI_Trainee : ModuleRules
{
	public AI_Trainee(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
