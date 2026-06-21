// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Player/FPSCharacter.h"
#include "FPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CYBERGUNNER_API AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay();
	
	UFUNCTION()
	void GoToGameOver();
};
