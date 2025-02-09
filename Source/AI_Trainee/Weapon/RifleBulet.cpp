// Fill out your copyright notice in the Description page of Project Settings.


#include "RifleBulet.h"
#include "Components/StaticMeshComponent.h"  // Для роботи з Skeletal Mesh
#include "Sound/SoundBase.h"  // Required for using USoundBase
#include "Kismet/GameplayStatics.h"


// Sets default values
ARifleBulet::ARifleBulet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Block);
	MeshComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap); // Enable overlap for world dynamic objects

	


}

// Called when the game starts or when spawned
void ARifleBulet::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->OnComponentHit.AddDynamic(this, &ARifleBulet::OnMeshHit);
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ARifleBulet::OnBeginOverlap);
}

// Called every frame
void ARifleBulet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARifleBulet::OnMeshHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (SoundToPlay && GetWorld())
	{
		FVector SoundLocation = MeshComponent->GetComponentLocation();
		UE_LOG(LogTemp, Warning, TEXT("Playing sound at: %s"), *SoundLocation.ToString());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SoundToPlay, SoundLocation);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Sound not played. Check if SoundToPlay or GetWorld() is null."));
	}
	Destroy();
	
}

void ARifleBulet::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	
}

