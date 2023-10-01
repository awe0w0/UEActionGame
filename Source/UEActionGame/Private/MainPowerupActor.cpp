// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPowerupActor.h"
#include "Components/SphereComponent.h"

// Sets default values
AMainPowerupActor::AMainPowerupActor()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Powerup");
	RootComponent = SphereComp;

	RespawnTime = 10.0f;

}

void AMainPowerupActor::Interact_Implementation(APawn* InstigatorPawn)
{
	// logic in derived classes...
}

void AMainPowerupActor::ShowPowerup()
{
	SetPowerupState(true);
}


void AMainPowerupActor::HideAndCooldownPowerup()
{
	SetPowerupState(false);

	GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &AMainPowerupActor::ShowPowerup, RespawnTime);
}

void AMainPowerupActor::SetPowerupState(bool bNewIsActive)
{
	SetActorEnableCollision(bNewIsActive);

	RootComponent->SetVisibility(bNewIsActive, true);
}


