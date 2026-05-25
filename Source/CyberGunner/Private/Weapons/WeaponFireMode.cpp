// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WeaponFireMode.h"
#include "Player/FPSCharacter.h"

void UWeaponFireMode::StartFire_Implementation(AFPSCharacter* Character) {}
void UWeaponFireMode::StopFire_Implementation(AFPSCharacter* Character) {}
void UWeaponFireMode::TickFire_Implementation(AFPSCharacter* Character, float DeltaTime) {}

void UWeaponFireMode::GetMuzzleLocationAndRotation(AFPSCharacter* Character, FVector& OutLocation, FRotator& OutRotation) const
{
	OutLocation = FVector::ZeroVector;
	OutRotation = FRotator::ZeroRotator;

	if (!Character) return;

	FVector CameraLocation;
	FRotator CameraRotation;
	Character->GetActorEyesViewPoint(CameraLocation, CameraRotation);

	FVector MuzzleOffset(100.0f, 0.0f, 0.0f); // Offset from the camera to the muzzle
	OutLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
	OutRotation = CameraRotation;
}

void UWeaponFireMode::SpawnDebugProjectile(AFPSCharacter* Character, const FVector& Location, const FRotator& Rotation)
{
    if (!Character || !DebugProjectileClass) return;

    UWorld* World = Character->GetWorld();
    if (!World) return;

    FActorSpawnParameters Params;
    Params.Owner = Character;
    Params.Instigator = Character;

    // USE THE ROTATION YOU WERE GIVEN
    AActor* SpawnedActor = World->SpawnActor<AActor>(DebugProjectileClass, Location, Rotation, Params);
    if (!SpawnedActor) return;
    UE_LOG(LogTemp, Warning, TEXT("Spawned at: %s"), *Location.ToString());


    // USE THE ROTATION YOU WERE GIVEN
    if (APlayerProjectile* Projectile = Cast<APlayerProjectile>(SpawnedActor))
    {
        Projectile->FireInDirection(Rotation.Vector());
    }
}

