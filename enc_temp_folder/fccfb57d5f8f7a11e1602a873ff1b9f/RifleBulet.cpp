// Fill out your copyright notice in the Description page of Project Settings.


#include "RifleBulet.h"
#include "Components/StaticMeshComponent.h"  // Для роботи з Skeletal Mesh

// Sets default values
ARifleBulet::ARifleBulet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	MeshComponent->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ARifleBulet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARifleBulet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

