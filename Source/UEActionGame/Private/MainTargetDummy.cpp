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
	//Trigger when health is changed
	AttributeComp->OnHealthChanged.AddDynamic(this, &AMainTargetDummy::OnHealthChanged);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMainTargetDummy::OnHealthChanged(AActor* InstigatorActor, UMainAttributesComponent* OwningComp, float NewHealth, float Delta) {
	if (Delta < 0.0f) {
		MeshComp->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);
	}
}
