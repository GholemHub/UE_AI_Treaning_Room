// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AI_NPC1.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"

// Sets default values
AAI_NPC1::AAI_NPC1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_NPC1::BeginPlay()
{
	Super::BeginPlay();

	if (BehaviorTree)
	{
		//RunBehaviorTree(BehaviorTree);
	}
	
}
 
// Called every frame
void AAI_NPC1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_NPC1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

