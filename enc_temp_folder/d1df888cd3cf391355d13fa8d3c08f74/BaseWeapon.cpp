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

    SocketNames = WeaponMesh->GetAllSocketNames();
    if (SocketNames.IsEmpty()) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "It is empty");
    }
    for (const FName& SocketName : SocketNames)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, SocketName.ToString());
        }
    }
    auto MuzzleSocket = WeaponMesh->GetSocketByName(FName("LeftHandSocket"));
        FRotator MuzzleRotation = WeaponMesh->GetComponentRotation();
        if (!MuzzleSocket) {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("MuzzleLocation"));
            }
        }
        ARifleBulet* Bullet = GetWorld()->SpawnActor<ARifleBulet>(BulletClass, FVector(1000,1000,100), MuzzleRotation);
        
        if (Bullet)
        {
            FVector MuzzleForward = GetActorForwardVector();

            //FVector Impulse = MuzzleForward * 1000.0f;
            Bullet->MeshComponent->AddImpulse(MuzzleForward, "fire_socket", 0);
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("FIRE!!!"));
            }
        }
    

	
}
