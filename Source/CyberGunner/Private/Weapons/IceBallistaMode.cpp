// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/IceBallistaMode.h"
#include "Player/FPSCharacter.h"

void UIceBallistaMode::StartFire_Implementation(AFPSCharacter* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Ice Ballista Charging")); //temp log
	SpawnDebugProjectile(Character);

}
