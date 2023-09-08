// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

#include "MainMagicProjectile.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComp->SetupAttachment(SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;

	// Set this character to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;


}

void AMainCharacter::ShootProjectile()
{
	// Create a projectile and set its spawn location and rotation
	FVector CameraLocation;
	FRotator CameraRotation;
	GetActorEyesViewPoint(CameraLocation, CameraRotation);

	FVector ShootDirection = CameraRotation.Vector();
	FVector StartLocation = CameraLocation + ShootDirection * 100.0f; // Adjust spawn location as needed

	// Spawn the projectile
	AMainMagicProjectile* Projectile = GetWorld()->SpawnActor<AMainMagicProjectile>(StartLocation, CameraRotation);

	// Set the projectile's initial velocity
	if (Projectile)
	{
		FVector LaunchDirection = CameraRotation.Vector();
		Projectile->FireInDirection(LaunchDirection);
	}
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Lookup", this, &APawn::AddControllerPitchInput);

	//PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AMainCharacter::PrimaryAttack);
	// Bind the input to the ShootProjectile function
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AMainCharacter::ShootProjectile);
}

void AMainCharacter::MoveForward(float Value) {
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), Value);
}

void AMainCharacter::MoveRight(float Value) {
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightVector, Value);
}

//void AMainCharacter::PrimaryAttack() {
//	FVector HandLocation = GetMesh()->GetSocketLocation("Muzzle_02");
//
//	FTransform SpawnTM = FTransform(GetControlRotation(), HandLocation);
//
//	FActorSpawnParameters SpawnParams;
//	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
//
//	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);
//}
