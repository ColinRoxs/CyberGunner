// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponFireMode.h"
#include "FlakCannonMode.generated.h"

/**
 * 
 */
UCLASS()
class CYBERGUNNER_API UFlakCannonMode : public UWeaponFireMode
{
	GENERATED_BODY()
	
public:
	virtual void StartFire_Implementation(AFPSCharacter* Character) override;
};
