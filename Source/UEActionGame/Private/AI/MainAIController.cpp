// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MainAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


void AMainAIController::BeginPlay() {

	Super::BeginPlay();

	if (ensureMsgf(BehaviorTree, TEXT("Behavior tree is nullptr! Please assign BehaviorTree in your AI Controller."))) {
		RunBehaviorTree(BehaviorTree);
	}

	

	//APawn* MyPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	//if (MyPawn) {
	//	GetBlackboardComponent()->SetValueAsVector("MoveToLocation", MyPawn->GetActorLocation());

	//	GetBlackboardComponent()->SetValueAsObject("TargetActor", MyPawn);
	//}
}