// Copyright Pizza Masters 5, All Rights Reserved.


#include "DemonController.h"
#include "Holy/Characters/Demon.h"

ADemonController::ADemonController()
{
}

void ADemonController::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetCharacter())
		Demon = Cast<ADemon>(GetCharacter());
	else
		UE_LOG(LogTemp, Warning, TEXT("Demon character not found"));
}

void ADemonController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	// Bind input axes
	InputComponent->BindAxis("Mouse_X", this, &ADemonController::IAxis_Look_X);
	InputComponent->BindAxis("Mouse_Y", this, &ADemonController::IAxis_Look_Y);
	InputComponent->BindAxis("WASD_X", this, &ADemonController::IAxis_Move_X);
	InputComponent->BindAxis("WASD_Y", this, &ADemonController::IAxis_Move_Y);

	// Bind input actions
	InputComponent->BindAction("Mouse_1", EInputEvent::IE_Pressed, this, &ADemonController::IAction_SpellL_Pressed);
	InputComponent->BindAction("Mouse_1", EInputEvent::IE_Released, this, &ADemonController::IAction_SpellL_Released);
	InputComponent->BindAction("Mouse_2", EInputEvent::IE_Pressed, this, &ADemonController::IAction_SpellR_Pressed);
	InputComponent->BindAction("Mouse_2", EInputEvent::IE_Released, this, &ADemonController::IAction_SpellR_Released);
	InputComponent->BindAction("Q", EInputEvent::IE_Pressed, this, &ADemonController::IAction_SpellLSwap_Pressed);
	InputComponent->BindAction("Q", EInputEvent::IE_Released, this, &ADemonController::IAction_SpellLSwap_Released);
	InputComponent->BindAction("E", EInputEvent::IE_Pressed, this, &ADemonController::IAction_SpellRSwap_Pressed);
	InputComponent->BindAction("E", EInputEvent::IE_Released, this, &ADemonController::IAction_SpellRSwap_Released);
	InputComponent->BindAction("Space", EInputEvent::IE_Pressed, this, &ADemonController::IAction_Jump_Pressed);
	InputComponent->BindAction("Space", EInputEvent::IE_Released, this, &ADemonController::IAction_Jump_Released);
	InputComponent->BindAction("Shift", EInputEvent::IE_Pressed, this, &ADemonController::IAction_Dash_Pressed);
	InputComponent->BindAction("Shift", EInputEvent::IE_Released, this, &ADemonController::IAction_Dash_Released);
}

void ADemonController::IAxis_Look_X(float Value)
{
	const FString debugString = FString::Printf(TEXT("IAxis_Look_X - %f"), Value);
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Cyan, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	if(Demon)
		Demon->Look_X(Value);
}

void ADemonController::IAxis_Look_Y(float Value)
{
	const FString debugString = FString::Printf(TEXT("IAxis_Look_Y - %f"), Value);
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Cyan, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	if(Demon)
		Demon->Look_Y(Value);
}

void ADemonController::IAxis_Move_X(float Value)
{
	const FString debugString = FString::Printf(TEXT("IAxis_Move_X - %f"), Value);
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	if(Demon)
		Demon->Move_X(Value);
}

void ADemonController::IAxis_Move_Y(float Value)
{
	const FString debugString = FString::Printf(TEXT("IAxis_Move_Y - %f"), Value);
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	if(Demon)
		Demon->Move_Y(Value);
}

void ADemonController::IAction_SpellL_Pressed()
{
	const FString debugString = FString::Printf(TEXT("IAction_SpellL_Pressed"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	if(Demon)
		Demon->CastSpell_L();
}

void ADemonController::IAction_SpellL_Released()
{
	const FString debugString = FString::Printf(TEXT("IAction_SpellL_Released"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
}

void ADemonController::IAction_SpellR_Pressed()
{
	const FString debugString = FString::Printf(TEXT("IAction_SpellR_Pressed"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	if(Demon)
		Demon->CastSpell_R();
}

void ADemonController::IAction_SpellR_Released()
{ 
	const FString debugString = FString::Printf(TEXT("IAction_SpellR_Released"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	
}

void ADemonController::IAction_SpellLSwap_Pressed()
{
	const FString debugString = FString::Printf(TEXT("IAction_SpellLSwap_Pressed"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	
}

void ADemonController::IAction_SpellLSwap_Released()
{
	const FString debugString = FString::Printf(TEXT("IAction_SpellLSwap_Released"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
}

void ADemonController::IAction_SpellRSwap_Pressed()
{
	const FString debugString = FString::Printf(TEXT("IAction_SpellRSwap_Pressed"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
}

void ADemonController::IAction_SpellRSwap_Released()
{
	const FString debugString = FString::Printf(TEXT("IAction_SpellRSwap_Released"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
}

void ADemonController::IAction_Jump_Pressed()
{
	const FString debugString = FString::Printf(TEXT("IAction_Jump_Pressed"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	if(Demon)
		Demon->Jump();
}

void ADemonController::IAction_Jump_Released()
{
	const FString debugString = FString::Printf(TEXT("IAction_Jump_Released"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);

	if(Demon)
		Demon->StopJumping();
}

void ADemonController::IAction_Dash_Pressed()
{
	const FString debugString = FString::Printf(TEXT("IAction_Dash_Pressed"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
}

void ADemonController::IAction_Dash_Released()
{
	const FString debugString = FString::Printf(TEXT("IAction_Dash_Released"));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
}
