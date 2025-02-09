// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AIController.h"


#include "AI_NPC1.generated.h"
class ABaseWeapon;
UCLASS()
class AI_TRAINEE_API AAI_NPC1 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_NPC1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void Fire();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<ABaseWeapon> WeaponClass;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void SpawnWeapon();
	
private:
	ABaseWeapon* Weapon;
};
