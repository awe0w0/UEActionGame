// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainTargetDummy.generated.h"

class UMainAttributesComponent;

UCLASS()
class UEACTIONGAME_API AMainTargetDummy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainTargetDummy();

protected:
	
	UPROPERTY(VisibleAnywhere)
	UMainAttributesComponent* AttributeComp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, UMainAttributesComponent* OwningComp, float NewHealth, float Delta);

};
