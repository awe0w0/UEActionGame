// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPowerupActor.h"

// Sets default values
AMainPowerupActor::AMainPowerupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainPowerupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainPowerupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

