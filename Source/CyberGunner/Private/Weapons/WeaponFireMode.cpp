// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WeaponFireMode.h"
#include "Player/FPSCharacter.h"

void UWeaponFireMode::StartFire_Implementation(AFPSCharacter* Character) {}
void UWeaponFireMode::StopFire_Implementation(AFPSCharacter* Character) {}
void UWeaponFireMode::TickFire_Implementation(AFPSCharacter* Character, float DeltaTime) {}

void UWeaponFireMode::SpawnDebugProjectile(AFPSCharacter* Character)
{
	if (!Character || !DebugProjectileClass) return;

	UWorld* World = Character->GetWorld();
	if (!World) return;

	FVector MuzzleLocation = Character->GetActorLocation() + Character->GetActorForwardVector() * 100.0f; // Spawn 100 units in front of the character

	FRotator MuzzleRotation = Character->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Character;
	SpawnParams.Instigator = Character->GetInstigator();

	AActor* Projectile = World->SpawnActor<AActor>(DebugProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
	if (!Projectile) return;
}