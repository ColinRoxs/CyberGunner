// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/DarkBurstMode.h"
#include "Player/FPSCharacter.h"

void UDarkBurstMode::StartFire_Implementation(AFPSCharacter* Character)
{
	if (bIsFiringBurst) return; // Prevent starting a new charge while firing a burst

	bIsCharging = true;
	LoadedRounds = 0;
	ChargeTimer = 0.f;
	UE_LOG(LogTemp, Warning, TEXT("Dark Burst Charging")); //temp log
}

void UDarkBurstMode::TickFire_Implementation(AFPSCharacter* Character, float DeltaTime)
{
	//Charging the burst
	if (bIsCharging)
	{
		if (LoadedRounds < MaxLoadedRounds)
		{
			ChargeTimer += DeltaTime;

			if (ChargeTimer >= ChargeInterval)
			{
				ChargeTimer = 0.f;

				LoadedRounds++;

				UE_LOG(LogTemp,Warning,TEXT("Loaded Round: %d"),LoadedRounds);
			}
		}
	}

	//Firing the burst
	if (bIsFiringBurst) 
	{
		BurstTimer += DeltaTime;

		if (BurstTimer >= BurstShotDelay) 
		{
			BurstTimer = 0.f;

			FVector MuzzleLocation;
			FRotator MuzzleRotation;

			GetMuzzleLocationAndRotation(Character, MuzzleLocation, MuzzleRotation);

			SpawnDebugProjectile(Character, MuzzleLocation, MuzzleRotation);

			RemainingBurstShots--;

			UE_LOG(LogTemp, Warning, TEXT("Burst Shot Fired! Remaining Shots: %d"), RemainingBurstShots);

			if (RemainingBurstShots <= 0)
			{
				bIsFiringBurst = false;
				UE_LOG(LogTemp, Warning, TEXT("Burst Finished!"));
			}
		}
	}
}

void UDarkBurstMode::StopFire_Implementation(AFPSCharacter * Character)
{
	if (!bIsCharging) return; 
	bIsCharging = false;

	if (LoadedRounds <= 0) return;

	bIsFiringBurst = true;

	RemainingBurstShots = LoadedRounds;

	BurstTimer = BurstShotDelay;

	UE_LOG(LogTemp, Warning, TEXT("Burst Started with %d shots!"), RemainingBurstShots);

	LoadedRounds = 0; // Reset loaded rounds after firing
}
