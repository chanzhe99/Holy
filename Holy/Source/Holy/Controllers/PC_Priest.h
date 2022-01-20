// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_Priest.generated.h"

/**
 * 
 */
UCLASS()
class HOLY_API APC_Priest : public APlayerController
{
	GENERATED_BODY()

public:
	APC_Priest();

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	// Keyboard input axes
	void IAxis_Look_Y(float Value);
	void IAxis_Look_X(float Value);
	void IAxis_Move_Y(float Value);
	void IAxis_Move_X(float Value);

	// Keyboard input actions
	void IAction_Shoot_Pressed();
	void IAction_Shoot_Released();
	void IAction_Jump_Pressed();
	void IAction_Jump_Released();
	void IAction_Dash_Pressed();
	void IAction_Dash_Released();
};
