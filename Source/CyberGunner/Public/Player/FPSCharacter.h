// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerProjectile.h"
#include "FPSCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UENUM(BlueprintType)
enum class EFireMode : uint8
{
	Mode1 UMETA(DispayName = "FlakCannon"),
	Mode2 UMETA(DispayName = "FireBeam"),
	Mode3 UMETA(DispayName = "ShockRounds"),
	Mode4 UMETA(DispayName = "IceBallista"),
	Mode5 UMETA(DispayName = "DarkBurst"),
};

UCLASS()
class CYBERGUNNER_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Enhanced Input assets

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ShootAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* FireMode1Action;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* FireMode2Action;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* FireMode3Action;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* FireMode4Action;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* FireMode5Action;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* FPSMeshComponent;

	UPROPERTY(EditAnywhere)
	FVector MuzzleOffset;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class APlayerProjectile> ProjectileClass;

	UFUNCTION()
	void Move(const FInputActionValue& Value);

	UFUNCTION()
	void Look(const FInputActionValue& Value);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void EndJump();

	UFUNCTION()
	void Shoot();

	UFUNCTION()
	void FlakMode();

	UFUNCTION()
	void BeamMode();

	UFUNCTION()
	void ShockMode();

	UFUNCTION()
	void IceMode();

	UFUNCTION()
	void DMMode();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	EFireMode CurrentFireMode = EFireMode::Mode1;

	UFUNCTION()
	void SwitchFireMode(const FInputActionValue& Value);

	UFUNCTION()
	void SetFireMode(EFireMode NewMode);
};
