// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCAIController.generated.h"

/**
 * 
 */
UCLASS()
class AI_TRAINEE_API ANPCAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void OnPossess(APawn*) override;
};
