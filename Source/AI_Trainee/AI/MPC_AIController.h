// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MPC_AIController.generated.h"
class UNPC1AIPerceptionComponent;
UCLASS()
class AI_TRAINEE_API AMPC_AIController : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float) override;
	virtual void OnPossess(APawn* InPawn)override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UNPC1AIPerceptionComponent* NPC1AIPerceptionComponent;
public:
	explicit AMPC_AIController(FObjectInitializer const&); 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FName FocusOnKeyName = "SelfActorrrr";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBlackboardData* BlackboardData;
private:
	AActor* GetFocusOnActor();

	
};
