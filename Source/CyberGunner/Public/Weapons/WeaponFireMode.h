// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeaponFireMode.generated.h"

class AFPSCharacter;

UCLASS(Abstract, Blueprintable, EditInLineNew, DefaultToInstanced)
class CYBERGUNNER_API UWeaponFireMode : public UObject
{
	GENERATED_BODY()
	
public:
	//Called when the player presses the fire button.
	UFUNCTION(BlueprintNativeEvent)
	void StartFire(AFPSCharacter* Character);
	virtual void StartFire_Implementation(AFPSCharacter* Character);

	//Called when the player releases the fire button.
	UFUNCTION(BlueprintNativeEvent)
	void StopFire(AFPSCharacter* Character);
	virtual void StopFire_Implementation(AFPSCharacter* Character);

	//Called every frame while the player is firing.
	UFUNCTION(BlueprintNativeEvent)
	void TickFire(AFPSCharacter* Character, float DeltaTime);
	virtual void TickFire_Implementation(AFPSCharacter* Character, float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	TSubclassOf<AActor> DebugProjectileClass;

protected:
	void SpawnDebugProjectile(AFPSCharacter* Character);
};
