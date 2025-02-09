// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FireWeaponTask.generated.h"

/**
 * 
 */
UCLASS()
class AI_TRAINEE_API UFireWeaponTask : public UBTTaskNode
{
	GENERATED_BODY()
	explicit UFireWeaponTask(FObjectInitializer const&);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:
	
};
