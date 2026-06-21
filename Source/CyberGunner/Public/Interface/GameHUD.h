// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Canvas.h"
#include "GameFramework/HUD.h"
#include "GameMenu.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class CYBERGUNNER_API AGameHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UTexture2D* CrosshairTexture;

	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UGameMenu> GameMenuClass;
	UGameMenu* GameMenuContainer;

	void SpawnGameMenu();

};
