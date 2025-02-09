// Fill out your copyright notice in the Description page of Project Settings.


#include "ROOMWeaponComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"  // Для роботи з акторами
#include "Kismet/GameplayStatics.h"  // Для створення ефектів, звуків, завдання шкоди
#include "Engine/World.h" 

// Sets default values for this component's properties
UROOMWeaponComponent::UROOMWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UROOMWeaponComponent::BeginPlay()
{

	
}


void UROOMWeaponComponent::Fire()
{
}

// Called every frame
void UROOMWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


