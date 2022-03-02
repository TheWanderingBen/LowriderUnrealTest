// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class LOWRIDER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UCameraComponent* Camera;

	void LookRightLeft(float axisvalue);
	void LookUpDown(float axisvalue);
	void MoveForwardBackward(float axisvalue);
	void MoveRightLeft(float axisvalue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
