// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponFireMode.h"
#include "DarkBurstMode.generated.h"

/**
 * 
 */
UCLASS()
class CYBERGUNNER_API UDarkBurstMode : public UWeaponFireMode
{
	GENERATED_BODY()
	
public:
	virtual void StartFire_Implementation(AFPSCharacter* Character) override;
	virtual void TickFire_Implementation(AFPSCharacter* Character, float DeltaTime) override;
	virtual void StopFire_Implementation(AFPSCharacter* Character) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|DarkBurst")
	int32 MaxLoadedRounds = 5;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|DarkBurst")
	float ChargeInterval = 0.25f;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|DarkBurst")
	float BurstShotDelay = 0.05f;

private:
	bool bIsCharging = false;
	int32 LoadedRounds = 0;
	float ChargeTimer = 0.f;

	bool bIsFiringBurst = false;
	int32 RemainingBurstShots = 0;
	float BurstTimer = 0.f;
};
