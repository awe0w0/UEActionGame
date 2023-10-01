// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainPowerupActor.h"
#include "MainPowerup_HealthPotion.generated.h"


class UStaticMeshComponent;


/**
 *
 */
UCLASS()
class UEACTIONGAME_API AMainPowerup_HealthPotion : public AMainPowerupActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, Category = "HealthPotion")
	int32 CreditCost;

public:

	void Interact_Implementation(APawn* InstigatorPawn);

	AMainPowerup_HealthPotion();
};
