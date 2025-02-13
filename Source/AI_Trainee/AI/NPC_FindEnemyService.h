// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"

#include "NPC_FindEnemyService.generated.h"

/**
 * 
 */
UCLASS()
class AI_TRAINEE_API UNPC_FindEnemyService : public UBTService
{
	GENERATED_BODY()
public:
	UNPC_FindEnemyService();
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	FBlackboardKeySelector EnemyActorKey;

	
};
