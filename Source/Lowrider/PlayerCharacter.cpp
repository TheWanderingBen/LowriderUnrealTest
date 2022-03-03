// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;

	this->GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = false;

	moveSpeed = 1.0f;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookHorizontal"), this, &APlayerCharacter::LookRightLeft);
	PlayerInputComponent->BindAxis(TEXT("LookVertical"), this, &APlayerCharacter::LookUpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveForwardBackward"), this, &APlayerCharacter::MoveForwardBackward);
	PlayerInputComponent->BindAxis(TEXT("MoveRightLeft"), this, &APlayerCharacter::MoveRightLeft);

}

void APlayerCharacter::LookRightLeft(float axisvalue)
{
	this->AddControllerYawInput(axisvalue);
}

void APlayerCharacter::LookUpDown(float axisvalue)
{
	this->AddControllerPitchInput(axisvalue);
}

void APlayerCharacter::MoveForwardBackward(float axisvalue)
{
	this->AddMovementInput(this->GetActorForwardVector() * axisvalue * moveSpeed);
}

void APlayerCharacter::MoveRightLeft(float axisvalue)
{
	this->AddMovementInput(this->GetActorRightVector() * axisvalue * moveSpeed);
}
