// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

#include "MainMagicProjectile.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MainInteractionComponent.h"
#include "MainAttributesComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	// 设置默认的跳跃力度
	JumpStrength = 500.0f; // 根据您的项目需求设置适当的值

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComp->SetupAttachment(SpringArmComp);

	InteractionComp = CreateDefaultSubobject<UMainInteractionComponent>("InteractionComp");

	AttributeComp = CreateDefaultSubobject<UMainAttributesComponent>("AttributeComp");

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;

	//// Set this character to call Tick() every frame.
	//PrimaryActorTick.bCanEverTick = true;


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

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AMainCharacter::PrimaryAttack);
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &AMainCharacter::PrimaryInteract);

	PlayerInputComponent->BindAxis("jump", this, &AMainCharacter::Jump);
	// Bind the input to the ShootProjectile function
	//PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AMainCharacter::ShootProjectile);
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

void AMainCharacter::PrimaryAttack() {
	PlayAnimMontage(AttackAnim);

	//UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance(); // 获取角色的动画实例，MeshComponent 是您的角色的骨骼网格组件

	//if (AnimInstance)
	//{
	//	// 设置要播放的 Montage
	//	UAnimMontage* MontageToPlay = AttackAnim; // 将 YourAttackAnimMontage 替换为您的攻击动画 Montage

	//	if (MontageToPlay)
	//	{
	//	// 设置 Montage 播放速率为 1.0，即最高权重
	//		float PlayRate = 1.0f;

	//		// 播放 Montage
	//		AnimInstance->Montage_Play(MontageToPlay, PlayRate);
	//	}
	//}

	GetWorldTimerManager().SetTimer(TimerHandle_PrimaryAttack, this, &AMainCharacter::PrimaryAttack_TimeElapsed, 0.2f);
	//GetWorldTimerManager().ClearTimer(TimerHandle_PrimaryAttack);


}

void AMainCharacter::Jump(float Value) {
	if (CanJump() && Value > 0.0f)
	{
		// 计算跳跃力度
		FVector JumpDirection = FVector(0.0f, 0.0f, 1.0f); // 垂直向上
		FVector JumpImpulse = JumpDirection * JumpStrength * Value;

		// 应用跳跃力度
		LaunchCharacter(JumpImpulse, false, false);
	}
}

void AMainCharacter::PrimaryInteract() {
	if (InteractionComp) {
		InteractionComp->PrimaryInteract();
	}
}

void AMainCharacter::PrimaryAttack_TimeElapsed() {
	if (ensure(ProjectileClass)) {
	FVector HandLocation = GetMesh()->GetSocketLocation("Muzzle_02");

	FTransform SpawnTM = FTransform(GetControlRotation(), HandLocation);

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Instigator = this;

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);
	}

}