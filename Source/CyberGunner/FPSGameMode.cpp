// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameMode.h"

void AFPSGameMode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, The game has started! Hybrid code worked!"));

	AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (PlayerCharacter) {
		PlayerCharacter->OnPlayerDied.AddDynamic(this, &AFPSGameMode::GoToGameOver);
	}
}

void AFPSGameMode::GoToGameOver()
{
	UGameplayStatics::OpenLevel(this, FName("Arena"));
}

