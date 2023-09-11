// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAttributesComponent.h"

// Sets default values for this component's properties
UMainAttributesComponent::UMainAttributesComponent()
{

	Health = 100.0f;
}


bool UMainAttributesComponent::ApplyHealthChange(float Delta) {
	Health += Delta;

	return true;
}

