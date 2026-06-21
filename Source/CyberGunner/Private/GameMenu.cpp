// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMenu.h"

void UGameMenu::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateHealthBar(1.0f);
	UpdateArmorBar(1.0f);
}

void UGameMenu::UpdateHealthBar(float HealthPercent)
{
	if (!HealthBar) 
	{
		return;
	}
	HealthBar->SetPercent(HealthPercent);
}

void UGameMenu::UpdateArmorBar(float ArmorPercent)
{
	if (!ArmorBar)
	{
		return;
	}
	ArmorBar->SetPercent(ArmorPercent);
}
