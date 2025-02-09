// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class ARifleBulet;
UCLASS()
class AI_TRAINEE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	

	UPROPERTY(EditAnywhere, Category = Weapon)
	float Damage = 20, f;

	UPROPERTY(EditAnywhere, Category = Weapon)
	int Ammo = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QQQQ")
	USkeletalMeshComponent* WeaponMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
	TSubclassOf<ARifleBulet> BulletClass;
	void Fire();
};
