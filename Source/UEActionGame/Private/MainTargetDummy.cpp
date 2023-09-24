// Fill out your copyright notice in the Description page of Project Settings.


#include "MainTargetDummy.h"
#include "Components/StaticMeshComponent.h"
#include "MainAttributesComponent.h"

// Sets default values
AMainTargetDummy::AMainTargetDummy()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	AttributeComp = CreateDefaultSubobject<UMainAttributesComponent>("AttributeComp");
	// Trigger when health is changed (damage/healing)
	AttributeComp->OnHealthChanged.AddDynamic(this, &AMainTargetDummy::OnHealthChanged);

}

void AMainTargetDummy::OnHealthChanged(AActor* InstigatorActor, UMainAttributesComponent* OwningComp, float NewHealth, float Delta) {
	if (Delta < 0.0f) {
		MeshComp->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);
	}
}