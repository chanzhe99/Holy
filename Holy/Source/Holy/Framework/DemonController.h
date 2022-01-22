// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DemonController.generated.h"

UCLASS()
class HOLY_API ADemonController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ADemonController();

	UPROPERTY()
	class ADemon* Demon;

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	// Keyboard input axes
	void IAxis_Look_X(float Value);
	void IAxis_Look_Y(float Value);
	void IAxis_Move_X(float Value);
	void IAxis_Move_Y(float Value);

	// Keyboard input actions
	void IAction_SpellL_Pressed();
	void IAction_SpellL_Released();
	void IAction_SpellR_Pressed();
	void IAction_SpellR_Released();
	void IAction_SpellLSwap_Pressed();
	void IAction_SpellLSwap_Released();
	void IAction_SpellRSwap_Pressed();
	void IAction_SpellRSwap_Released();
	void IAction_Jump_Pressed();
	void IAction_Jump_Released();
	void IAction_Dash_Pressed();
	void IAction_Dash_Released();
};
