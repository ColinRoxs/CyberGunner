// Fill out your copyright notice in the Description page of Project Settings.

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/FPSCharacter.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!FPSCameraComponent) {
		FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
		FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
		FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
		FPSCameraComponent->bUsePawnControlRotation = true;
	}

	if (!FPSMeshComponent) {
		FPSMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
		FPSMeshComponent->SetupAttachment(FPSCameraComponent);
		FPSMeshComponent->bCastDynamicShadow = false;
		FPSMeshComponent->CastShadow = false;
	}

	GetMesh()->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())) 
	{
		if (PlayerMappingContext) 
		{
			UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
			if (Subsystem) 
			{
				Subsystem->AddMappingContext(PlayerMappingContext, 0);
			}
		}
	}
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		if (MoveAction) 
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Move);
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Look);
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AFPSCharacter::StartJump);
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AFPSCharacter::EndJump);
			EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &AFPSCharacter::Shoot);
			EnhancedInputComponent->BindAction(FireMode1Action, ETriggerEvent::Started, this, &AFPSCharacter::FlakMode);
			EnhancedInputComponent->BindAction(FireMode2Action, ETriggerEvent::Started, this, &AFPSCharacter::BeamMode);
			EnhancedInputComponent->BindAction(FireMode3Action, ETriggerEvent::Started, this, &AFPSCharacter::ShockMode);
			EnhancedInputComponent->BindAction(FireMode4Action, ETriggerEvent::Started, this, &AFPSCharacter::IceMode);
			EnhancedInputComponent->BindAction(FireMode5Action, ETriggerEvent::Started, this, &AFPSCharacter::DMMode);
			
		}
	}
}

void AFPSCharacter::Move(const FInputActionValue& Value) 
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);
}

void AFPSCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D lookAxisVector = Value.Get<FVector2D>();
	AddControllerYawInput(lookAxisVector.X);
	AddControllerPitchInput(lookAxisVector.Y);
}

void AFPSCharacter::StartJump()
{
	bPressedJump = true;
}

void AFPSCharacter::EndJump()
{
	bPressedJump = false;
}

void AFPSCharacter::Shoot()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Pressed"));

	if (!ProjectileClass) return;

	FVector CameraLocation;
	FRotator CameraRotation;
	GetActorEyesViewPoint(CameraLocation, CameraRotation);

	MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

	FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

	FRotator MuzzleRotation = CameraRotation;
	MuzzleRotation.Pitch += 5.0f;

	UWorld* World = GetWorld();
	if (!World) return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	APlayerProjectile* Projectile = World->SpawnActor<APlayerProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
	if (!Projectile) return;

	FVector LaunchDirection = MuzzleRotation.Vector();
	Projectile->FireInDirection(LaunchDirection);
}

void AFPSCharacter::FlakMode()
{
	SetFireMode(EFireMode::Mode1);
}

void AFPSCharacter::BeamMode()
{
	SetFireMode(EFireMode::Mode2);
}

void AFPSCharacter::ShockMode()
{
	SetFireMode(EFireMode::Mode3);
}

void AFPSCharacter::IceMode()
{
	SetFireMode(EFireMode::Mode4);
}

void AFPSCharacter::DMMode()
{
	SetFireMode(EFireMode::Mode5);
}

void AFPSCharacter::SwitchFireMode(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
		return;

	int32 ModeIndex = static_cast<int32>(CurrentFireMode);

	ModeIndex = (ModeIndex + 1) % 5;

	CurrentFireMode = static_cast<EFireMode>(ModeIndex);

	switch (CurrentFireMode)
	{
	case EFireMode::Mode1:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Flak spread mode"))
		break;

	case EFireMode::Mode2:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Fire beam mode"))
		break;

	case EFireMode::Mode3:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Shock rounds mode"))
		break;

	case EFireMode::Mode4:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Ice Ballista mode"))
		break;

	case EFireMode::Mode5:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Dark Burst mode"))
		break;
	}
}

void AFPSCharacter::SetFireMode(EFireMode NewMode)
{
	CurrentFireMode = NewMode;

	switch (CurrentFireMode)
	{
	case EFireMode::Mode1:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Flak spread mode"))
			break;

	case EFireMode::Mode2:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Fire beam mode"))
			break;

	case EFireMode::Mode3:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Shock rounds mode"))
			break;

	case EFireMode::Mode4:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Ice Ballista mode"))
			break;

	case EFireMode::Mode5:
		UE_LOG(LogTemp, Warning, TEXT("Switched to Dark Burst mode"))
			break;
	}
}

