// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RifleBulet.generated.h"

UCLASS()
class AI_TRAINEE_API ARifleBulet : public AActor
{
	GENERATED_BODY()
	
public:	
	ARifleBulet();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	UStaticMeshComponent* MeshComponent;
};
