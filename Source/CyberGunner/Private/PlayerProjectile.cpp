// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerProjectile.h"

// Sets default values
APlayerProjectile::APlayerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->InitSphereRadius(15.0f);
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	CollisionComponent->OnComponentHit.AddDynamic(this, &APlayerProjectile::OnObjectHit);
	RootComponent = CollisionComponent;

	ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
	ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
	ProjectileMeshComponent->SetupAttachment(RootComponent);



	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = BulletSpeed;
	ProjectileMovementComponent->MaxSpeed = BulletSpeed;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f; // No gravity

	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void APlayerProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerProjectile::FireInDirection(const FVector& ShootDirection)
{
	// 1. FVector ShootDirection: Pass by value, least efficient. Making a copy of the vector every time we call this function.
	// 2. FVector* ShootDirection: Pass pointer, efficient cus memory address. But need to dereference the pointer to get the value, or be careful when updating the memory
	// 3. FVector& ShootDirection: Pass by reference, efficient and safe. No need to dereference, but still can update the value of the vector if needed. This is the best option for this function.
	// 4. const FVector& ShootDirection: Pass by const reference, efficient and safe. No need to dereference, but cannot update the value of the vector. This is the best option for this function if we don't need to update the shoot direction.

	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;

}

void APlayerProjectile::OnObjectHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics()) {
		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
		Destroy();
	}
}
