// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainGameplayInterface.h"
#include "MainPowerupActor.generated.h"


class USphereComponent;
class UStaticMeshComponent;


UCLASS(ABSTRACT)
class UEACTIONGAME_API AMainPowerupActor : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, Category = "Powerup")
	float RespawnTime;

	FTimerHandle TimerHandle_RespawnTimer;

	UFUNCTION()
	void ShowPowerup();

	void HideAndCooldownPowerup();

	void SetPowerupState(bool bNewIsActive);

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

public:

	void Interact_Implementation(APawn* InstigatorPawn);


public:

	AMainPowerupActor();

};
