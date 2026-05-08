// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/ShockRoundsMode.h"
#include "Player/FPSCharacter.h"

void UShockRoundsMode::StartFire_Implementation(AFPSCharacter* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Shock Rounds Fired")); //temp log
	SpawnDebugProjectile(Character);

}
