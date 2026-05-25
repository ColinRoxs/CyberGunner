// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponFireMode.h"
#include "FireBeamMode.generated.h"

UCLASS()
class CYBERGUNNER_API UFireBeamMode : public UWeaponFireMode
{
	GENERATED_BODY()
	
public:
	virtual void StartFire_Implementation(AFPSCharacter* Character) override;
	virtual void TickFire_Implementation(AFPSCharacter* Character, float DeltaTime) override;
	virtual void StopFire_Implementation(AFPSCharacter* Character) override;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Beam")
	float MaxBeamDistance = 10000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Beam")
	float DamagePerSecond = 20.0f;
};
