// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI_TraineeGameMode.h"
#include "AI_TraineeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAI_TraineeGameMode::AAI_TraineeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
