// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/IceBallistaMode.h"
#include "Player/FPSCharacter.h"

void UIceBallistaMode::StartFire_Implementation(AFPSCharacter* Character)
{
	bIsCharging = true;
	CurrentChargeTime = 0.0f;

	UE_LOG(LogTemp, Warning, TEXT("Ice Ballista Charging Started")); //temp log
}

void UIceBallistaMode::TickFire_Implementation(AFPSCharacter* Character, float DeltaTime)
{
	if (!bIsCharging) return;

	CurrentChargeTime += DeltaTime;
	CurrentChargeTime = FMath::Clamp(CurrentChargeTime, 0.0f, MaxChargeTime);
}

void UIceBallistaMode::StopFire_Implementation(AFPSCharacter * Character)
{
	if (!bIsCharging) return;
	bIsCharging = false;

	const float ChargeRatio = CurrentChargeTime / MaxChargeTime;
	const float FinalScale = FMath::Lerp(MinProjectileScale, MaxProjectileScale, ChargeRatio);

	FVector MuzzleLocation;
	FRotator MuzzleRotation;
	GetMuzzleLocationAndRotation(Character, MuzzleLocation, MuzzleRotation);
	
	UE_LOG(LogTemp, Warning, TEXT("Ice Ballista Charging")); //temp log

	SpawnDebugProjectile(Character, MuzzleLocation, MuzzleRotation);


	CurrentChargeTime = 0.0f;


}
