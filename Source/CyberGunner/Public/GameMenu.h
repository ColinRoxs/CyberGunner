// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "GameMenu.generated.h"

/**
 * 
 */
UCLASS()
class CYBERGUNNER_API UGameMenu : public UUserWidget
{
	GENERATED_BODY()
	

public: 
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ArmorBar;

	UFUNCTION()
	void UpdateHealthBar(float HealthPercent);

	UFUNCTION()
	void UpdateArmorBar(float ArmorPercent);
};
