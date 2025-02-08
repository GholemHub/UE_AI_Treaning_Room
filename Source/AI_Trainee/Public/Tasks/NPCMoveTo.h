// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "NPCMoveTo.generated.h"

/**
 * 
 */
UCLASS()
class AI_TRAINEE_API UNPCMoveTo : public UBTTaskNode
{
	GENERATED_BODY()
public:
	explicit UNPCMoveTo(FObjectInitializer const&);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float Radius = 1000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FBlackboardKeySelector AimLocationKey;
};