// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UMainInteractionComponent;
class UAnimMontage;
class UMainAttributesComponent;

UCLASS()
class UEACTIONGAME_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	FTimerHandle TimerHandle_PrimaryAttack;
public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Declare a function to shoot the projectile
	//UFUNCTION(BlueprintCallable, Category = "MainCharacter")
	//void ShootProjectile();

protected:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	UMainInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UMainAttributesComponent* AttributeComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	
	void MoveRight(float Value);
	
	void Jump(float Value);
	
	void PrimaryAttack();
	
	void PrimaryInteract();
	
	void PrimaryAttack_TimeElapsed();

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, UMainAttributesComponent* OwningComp, float NewHealth, float Delta);

	virtual void PostInitializeComponents() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ÉùÃ÷ JumpStrength ±äÁ¿
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	float JumpStrength;

};
