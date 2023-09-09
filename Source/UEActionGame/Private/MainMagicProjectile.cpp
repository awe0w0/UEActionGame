// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMagicProjectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMainMagicProjectile::AMainMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SetActorHiddenInGame(false); // 确保投射物在游戏中可见
	
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Projectile");
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 10000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;

	

}

// Called when the game starts or when spawned
void AMainMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AMainMagicProjectile::FireInDirection(const FVector& ShootDirection)
//{
//	// Set the initial velocity of the projectile
//	UProjectileMovementComponent* ProjectileMovement = FindComponentByClass<UProjectileMovementComponent>();
//	if (ProjectileMovement)
//	{
//		// Set the velocity based on the specified direction
//		ProjectileMovement->Velocity = ShootDirection * ProjectileMovement->InitialSpeed;
//	}
//}