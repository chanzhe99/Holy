// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_Priest.h"

APC_Priest::APC_Priest()
{
}

void APC_Priest::BeginPlay()
{
	Super::BeginPlay();

	if(GetCharacter())
	{
		// Get priest character actor
	}
}

void APC_Priest::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Bind input axes
	InputComponent->BindAxis("Mouse_Y", this, &APC_Priest::IAxis_Look_Y);
	InputComponent->BindAxis("Mouse_X", this, &APC_Priest::IAxis_Look_X);
	InputComponent->BindAxis("WASD_Y", this, &APC_Priest::IAxis_Move_Y);
	InputComponent->BindAxis("WASD_X", this, &APC_Priest::IAxis_Move_X);

	// Bind input actions
	InputComponent->BindAction("Mouse1", EInputEvent::IE_Pressed, this, &APC_Priest::IAction_Shoot_Pressed);
	InputComponent->BindAction("Mouse1", EInputEvent::IE_Released, this, &APC_Priest::IAction_Shoot_Released);
	InputComponent->BindAction("Space", EInputEvent::IE_Pressed, this, &APC_Priest::IAction_Jump_Pressed);
	InputComponent->BindAction("Space", EInputEvent::IE_Released, this, &APC_Priest::IAction_Jump_Released);
	InputComponent->BindAction("Shift", EInputEvent::IE_Pressed, this, &APC_Priest::IAction_Dash_Released);
	InputComponent->BindAction("Shift", EInputEvent::IE_Released, this, &APC_Priest::IAction_Dash_Pressed);

	 
	
}

void APC_Priest::IAxis_Move_Y(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("IAxis_Move_Y - %f"), Value);
}

void APC_Priest::IAxis_Move_X(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("IAxis_Move_X - %f"), Value);
}

void APC_Priest::IAxis_Look_Y(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("IAxis_Look_Y - %f"), Value);
}

void APC_Priest::IAxis_Look_X(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("IAxis_Move_X - %f"), Value);
}

void APC_Priest::IAction_Shoot_Pressed()
{
	UE_LOG(LogTemp, Warning, TEXT("IAction_Shoot_Pressed"));
}

void APC_Priest::IAction_Shoot_Released()
{
	UE_LOG(LogTemp, Warning, TEXT("IAction_Shoot_Released"));
}

void APC_Priest::IAction_Jump_Pressed()
{
	UE_LOG(LogTemp, Warning, TEXT("IAction_Jump_Pressed"));
}

void APC_Priest::IAction_Jump_Released()
{
	UE_LOG(LogTemp, Warning, TEXT("IAction_Jump_Released"));
}

void APC_Priest::IAction_Dash_Pressed()
{
	UE_LOG(LogTemp, Warning, TEXT("IAction_Dash_Pressed"));
}

void APC_Priest::IAction_Dash_Released()
{
	UE_LOG(LogTemp, Warning, TEXT("IAction_Dash_Released"));
}
