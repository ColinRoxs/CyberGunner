// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/FlakCannonMode.h"
#include "Player/FPSCharacter.h"

void UFlakCannonMode::StartFire_Implementation(AFPSCharacter* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Flak Cannon Fired")); //temp log
	SpawnDebugProjectile(Character);

}
