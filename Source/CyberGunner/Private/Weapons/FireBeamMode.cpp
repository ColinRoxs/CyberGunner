// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/FireBeamMode.h"
#include "Player/FPSCharacter.h"

void UFireBeamMode::StartFire_Implementation(AFPSCharacter* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Beam Fired")); //temp log
	SpawnDebugProjectile(Character);

}
