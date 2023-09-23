// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MainAttributesComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, InstigatorActor, UMainAttributesComponent*, OwningComp, float, NewHealth, float, Delta);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UEACTIONGAME_API UMainAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMainAttributesComponent();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Health;


public:	

	UFUNCTION(BlueprintCallable)
	bool IsAlive();

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool ApplyHealthChange(float Delta);

		
};
