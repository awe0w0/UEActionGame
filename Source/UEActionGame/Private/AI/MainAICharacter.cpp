// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MainAICharacter.h"
#include "Perception/PawnSensingComponent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"



AMainAICharacter::AMainAICharacter()
{
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>("PawmSensingComp");

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

}

void AMainAICharacter::PostInitializeComponents() {
	Super::PostInitializeComponents();

	PawnSensingComp->OnSeePawn.AddDynamic(this, &AMainAICharacter::OnPawnSeen);
}

void AMainAICharacter::OnPawnSeen(APawn* Pawn) {
	AAIController* AIC = Cast<AAIController>(GetController());
	if (AIC) {
		UBlackboardComponent* BBComp = AIC->GetBlackboardComponent();

		BBComp->SetValueAsObject("TargetActor", Pawn);

		DrawDebugString(GetWorld(), GetActorLocation(), "PLAYER SPOTTED", nullptr, FColor::White, 4.0f, true);
	}
}
