// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "NPC1AIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class AI_TRAINEE_API UNPC1AIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()
public:
	AActor* GetClosestEnemy() const; 
};
