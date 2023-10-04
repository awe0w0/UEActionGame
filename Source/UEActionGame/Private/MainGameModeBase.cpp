// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "EnvironmentQuery/EnvQueryManager.h"	
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/EnvQueryInstanceBlueprintWrapper.h"
#include "AI/MainAICharacter.h"
#include "MainAttributesComponent.h"
#include "EngineUtils.h"

AMainGameModeBase::AMainGameModeBase() {
	SpawnTimerInterval = 2.0f;
	
}

void AMainGameModeBase::StartPlay() {
	Super::StartPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_SpawnBots, this, &AMainGameModeBase::SpawnBotTimerElapsed, SpawnTimerInterval, true);
}

void AMainGameModeBase::SpawnBotTimerElapsed() {
	UEnvQueryInstanceBlueprintWrapper* QueryInstance = UEnvQueryManager::RunEQSQuery(this, SpawnBotQuery, this, EEnvQueryRunMode::RandomBest5Pct, nullptr);
	
	if (ensure(QueryInstance)) {
		QueryInstance->GetOnQueryFinishedEvent().AddDynamic(this, &AMainGameModeBase::OnQueryCompleted);

	}
}

void AMainGameModeBase::OnQueryCompleted(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus) {
	if (QueryStatus != EEnvQueryStatus::Success) {
		UE_LOG(LogTemp, Warning, TEXT("Spawn bot EQS Query Failed!"));
		return;
	}
	
	int32 NrOfAliveBots = 0;
	for (TActorIterator<AMainAICharacter> It(GetWorld()); It; ++It) {
		AMainAICharacter* Bot = *It;

		UMainAttributesComponent* AttributeComp = Cast<UMainAttributesComponent>(Bot->GetComponentByClass(UMainAttributesComponent::StaticClass()));
		if (AttributeComp && AttributeComp->IsAlive()) {
			NrOfAliveBots++;
		}
	}
	float MaxBotCount = 10.0f;

	if (DifficultyCurve) {
		MaxBotCount = DifficultyCurve->GetFloatValue(GetWorld()->TimeSeconds);
	}

	if (NrOfAliveBots >= MaxBotCount) {
		return;
	}
	
	TArray<FVector> Locations = QueryInstance->GetResultsAsLocations();
	
	if (Locations.IsValidIndex(0)) {
		GetWorld()->SpawnActor<AActor>(MinionClass, Locations[0], FRotator::ZeroRotator);
	}
}