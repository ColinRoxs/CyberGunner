// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface/GameHUD.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("GameHUD BeginPlay"));

	SpawnGameMenu();
}

void AGameHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTexture) return;

	float CanvasWidth = Canvas->ClipX;
	float CanvasHeight = Canvas->ClipY;
	FVector2D Center(CanvasWidth * 0.5f, CanvasHeight * 0.5f);

	float CrosshairWidth = CrosshairTexture->GetSurfaceWidth();
	float CrosshairHeight = CrosshairTexture->GetSurfaceHeight();

	float AlignmentX = 0.5;
	float AlignmentY = 0.5;
	FVector2D CrosshairPosOffset(CrosshairWidth * AlignmentX, CrosshairHeight * AlignmentY);

	// Draw Settings
	FVector2D FinalCrosshairPos = Center - CrosshairPosOffset;

	float CrosshairScale = 2.5f;
	FVector2D FinalCrosshairSize(CrosshairWidth * CrosshairScale, CrosshairHeight * CrosshairScale);

	// Draw the crosshair
	FCanvasTileItem TileItem(FinalCrosshairPos, CrosshairTexture->GetResource(), FinalCrosshairSize, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

void AGameHUD::SpawnGameMenu()
{
	if (GameMenuContainer) 
	{
		GameMenuContainer->RemoveFromParent();
		GameMenuContainer = nullptr;
	}

	GameMenuContainer = CreateWidget<UGameMenu>(GetWorld(), GameMenuClass);
	GameMenuContainer->AddToViewport();

	PlayerOwner->bShowMouseCursor = false;
	PlayerOwner->SetInputMode(FInputModeGameOnly());
}
