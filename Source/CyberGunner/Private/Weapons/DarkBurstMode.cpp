// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/DarkBurstMode.h"
#include "Player/FPSCharacter.h"

void UDarkBurstMode::StartFire_Implementation(AFPSCharacter* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Dark Burst Charging")); //temp log
	SpawnDebugProjectile(Character);

}
