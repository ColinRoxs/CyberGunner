// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/FireBeamMode.h"
#include "Player/FPSCharacter.h"

void UFireBeamMode::StartFire_Implementation(AFPSCharacter* Character)
{
	FVector MuzzleLocation;
	FRotator MuzzleRotation;
	GetMuzzleLocationAndRotation(Character, MuzzleLocation, MuzzleRotation);

	UE_LOG(LogTemp, Warning, TEXT("Fire Beam Fired")); //temp log
	SpawnDebugProjectile(Character, MuzzleLocation, MuzzleRotation);

}

void UFireBeamMode::TickFire_Implementation(AFPSCharacter* Character, float DeltaTime)
{}

void UFireBeamMode::StopFire_Implementation(AFPSCharacter * Character)
{}
