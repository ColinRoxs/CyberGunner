// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/ShockRoundsMode.h"
#include "Player/FPSCharacter.h"

void UShockRoundsMode::StartFire_Implementation(AFPSCharacter* Character)
{
	bIsFiring = true;
	TimeSinceLastShot = FireRate; // Allow immediate firing when the player starts firing
}

void UShockRoundsMode::TickFire_Implementation(AFPSCharacter* Character, float DeltaTime)
{
	if (!bIsFiring) return;

	TimeSinceLastShot += DeltaTime;

	if (TimeSinceLastShot >= FireRate)
	{
		TimeSinceLastShot = 0.0f;

		FVector MuzzleLocation;
		FRotator MuzzleRotation;
		GetMuzzleLocationAndRotation(Character, MuzzleLocation, MuzzleRotation);

		UE_LOG(LogTemp, Warning, TEXT("Shock Rounds fired!"));

		SpawnDebugProjectile(Character, MuzzleLocation, MuzzleRotation);
	}
}

void UShockRoundsMode::StopFire_Implementation(AFPSCharacter * Character)
{
	bIsFiring = false;
}
