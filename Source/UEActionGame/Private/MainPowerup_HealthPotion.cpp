// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPowerup_HealthPotion.h"
#include "MainAttributesComponent.h"




AMainPowerup_HealthPotion::AMainPowerup_HealthPotion()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);
}


void AMainPowerup_HealthPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	UMainAttributesComponent* AttributeComp = Cast<UMainAttributesComponent>(InstigatorPawn->GetComponentByClass(UMainAttributesComponent::StaticClass()));
	// Check if not already at max health
	if (ensure(AttributeComp) && !AttributeComp->IsFullHealth())
	{
			if (AttributeComp->ApplyHealthChange(AttributeComp->GetHealthMax()))
			{
				// Only activate if healed successfully
				HideAndCooldownPowerup();
			}
	}
}

