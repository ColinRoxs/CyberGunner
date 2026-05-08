// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WeaponFireMode.h"
#include "Player/FPSCharacter.h"

void UWeaponFireMode::StartFire_Implementation(AFPSCharacter* Character) {}
void UWeaponFireMode::StopFire_Implementation(AFPSCharacter* Character) {}
void UWeaponFireMode::TickFire_Implementation(AFPSCharacter* Character, float DeltaTime) {}

void UWeaponFireMode::SpawnDebugProjectile(AFPSCharacter* Character)
{
	if (!Character || !DebugProjectileClass) return;

	FVector CameraLocation;
	FRotator CameraRotation;
	Character->GetActorEyesViewPoint(CameraLocation, CameraRotation);

	FVector MuzzleOffset(100.0f, 0.0f, 0.0f); // Offset from the camera to the muzzle
	FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

	FRotator MuzzleRotation = CameraRotation;
	MuzzleRotation.Pitch += 5.0f;

	UWorld* World = Character->GetWorld();
	if (!World) return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Character;
	SpawnParams.Instigator = Character;

	AActor* SpawnedActor = World->SpawnActor<AActor>(DebugProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
	if (!SpawnedActor) return;

	if (APlayerProjectile* Projectile = Cast<APlayerProjectile>(SpawnedActor))
	{
		FVector LaunchDirection = MuzzleRotation.Vector();
		Projectile->FireInDirection(LaunchDirection);
	}
}