// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MainAICharacter.h"

// Sets default values
AMainAICharacter::AMainAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

