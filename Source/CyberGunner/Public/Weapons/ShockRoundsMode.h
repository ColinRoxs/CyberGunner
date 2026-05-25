// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponFireMode.h"
#include "ShockRoundsMode.generated.h"

/**
 * 
 */
UCLASS()
class CYBERGUNNER_API UShockRoundsMode : public UWeaponFireMode
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|ShockRounds")
	float FireRate = 0.12f;

	float TimeSinceLastShot = 0.0f;
	bool bIsFiring = false;

	virtual void StartFire_Implementation(AFPSCharacter* Character) override;
	virtual void TickFire_Implementation(AFPSCharacter* Character, float DeltaTime) override;
	virtual void StopFire_Implementation(AFPSCharacter* Character) override;
	
};
