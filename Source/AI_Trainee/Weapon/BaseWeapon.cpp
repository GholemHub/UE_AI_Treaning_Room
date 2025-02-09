// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "RifleBulet.h"
#include "Engine/Engine.h"
#include "Components/SkeletalMeshComponent.h"  // Для роботи з Skeletal Mesh
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Gameframework/CharacterMovementComponent.h"
#include "Components/PrimitiveComponent.h"



// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseWeapon::Fire()
{
	if (!WeaponMesh) return;
    TArray<FName> SocketNames;
    FVector MuzzleLocation = WeaponMesh->GetSocketLocation(FName("fire_socket")); 
    FRotator MuzzleRotation = WeaponMesh->GetSocketRotation(FName("fire_socket"));
       
    ARifleBulet* Bullet = GetWorld()->SpawnActor<ARifleBulet>(BulletClass, MuzzleLocation, MuzzleRotation);
        
    if (Bullet)
    {
        FVector MuzzleForward = WeaponMesh->GetSocketRotation(FName("fire_socket")).Vector(); // Get direction of the muzzle

        //FVector Impulse = MuzzleForward * 10000.0f;
        Bullet->MeshComponent->AddImpulse(MuzzleForward * 1000.0f);

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("FIRE!!!"));
        }
    }	
}
