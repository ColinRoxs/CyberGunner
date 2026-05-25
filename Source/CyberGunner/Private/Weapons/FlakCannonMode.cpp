// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/FlakCannonMode.h"
#include "Player/FPSCharacter.h"

static const TArray<FVector> PelletSpread =
{
	FVector(1.f,  0.00f,  0.00f),
	FVector(1.f, -0.01f,  0.01f),
	FVector(1.f,  0.01f,  0.01f),
	FVector(1.f, -0.01f,  0.01f),
	FVector(1.f,  0.01f, -0.01f),
};

void UFlakCannonMode::StartFire_Implementation(AFPSCharacter* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Flak Cannon Fired")); //temp log
	
	FVector MuzzleLocation;
	FRotator MuzzleRotation;
	GetMuzzleLocationAndRotation(Character, MuzzleLocation, MuzzleRotation);


    for (const FVector& SpreadDirection : PelletSpread)
    {
        // Convert local spread pattern into world space
        FVector WorldDirection =
            MuzzleRotation
            .RotateVector(SpreadDirection)
            .GetSafeNormal();

        // Convert direction vector into projectile rotation
        FRotator PelletRotation = WorldDirection.Rotation();

        // Spawn projectile
        SpawnDebugProjectile(Character, MuzzleLocation, PelletRotation);

        UE_LOG(
            LogTemp,
            Warning,
            TEXT("Pellet Direction: %s"),
            *WorldDirection.ToString()
        );
    }
}
