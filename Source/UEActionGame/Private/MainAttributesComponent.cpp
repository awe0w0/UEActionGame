// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAttributesComponent.h"

// Sets default values for this component's properties
UMainAttributesComponent::UMainAttributesComponent()
{

	HealthMax = 100;
	Health = HealthMax;
}

bool UMainAttributesComponent::IsAlive() const {
	return Health > 0.0f;
}

bool UMainAttributesComponent::ApplyHealthChange(float Delta) {
	Health += Delta;

	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);

	return true;
}

bool UMainAttributesComponent::IsFullHealth() const
{
	return Health == HealthMax;
}


float UMainAttributesComponent::GetHealth() const
{
	return Health;
}

float UMainAttributesComponent::GetHealthMax() const
{
	return HealthMax;
}

void UMainAttributesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}