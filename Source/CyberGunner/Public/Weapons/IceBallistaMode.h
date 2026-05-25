// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponFireMode.h"
#include "IceBallistaMode.generated.h"

/**
 * 
 */
UCLASS()
class CYBERGUNNER_API UIceBallistaMode : public UWeaponFireMode
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|IceBallista")
	float MaxChargeTime = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|IceBallista")
	float MinProjectileScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|IceBallista")
	float MaxProjectileScale = 12.0f;

protected:
	bool bIsCharging = false;
	float CurrentChargeTime = 0.0f;

public:
	virtual void StartFire_Implementation(AFPSCharacter* Character) override;
	virtual void TickFire_Implementation(AFPSCharacter* Character, float DeltaTime) override;
	virtual void StopFire_Implementation(AFPSCharacter* Character) override;
};