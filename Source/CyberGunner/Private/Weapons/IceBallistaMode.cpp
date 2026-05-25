// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/IceBallistaMode.h"
#include "Player/FPSCharacter.h"

void UIceBallistaMode::StartFire_Implementation(AFPSCharacter* Character)
{
	FVector MuzzleLocation;
	FRotator MuzzleRotation;
	GetMuzzleLocationAndRotation(Character, MuzzleLocation, MuzzleRotation);

	UE_LOG(LogTemp, Warning, TEXT("Ice Ballista Charging")); //temp log
	SpawnDebugProjectile(Character, MuzzleLocation, MuzzleRotation);

}

void UIceBallistaMode::TickFire_Implementation(AFPSCharacter* Character, float DeltaTime)
{}

void UIceBallistaMode::StopFire_Implementation(AFPSCharacter * Character)
{}
