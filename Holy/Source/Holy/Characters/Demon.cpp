// Copyright Pizza Masters 5, All Rights Reserved.


#include "Demon.h"

// Sets default values
ADemon::ADemon()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADemon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADemon::Look_X(float Value)
{
	AddControllerYawInput(Value);
}

void ADemon::Look_Y(float Value)
{
	AddControllerPitchInput(Value);
}

void ADemon::Move_X(float Value)
{
	if (Value != 0)
		AddMovementInput(GetActorForwardVector(), Value);
}

void ADemon::Move_Y(float Value)
{
	if (Value != 0)
		AddMovementInput(GetActorRightVector(), Value);
}

void ADemon::CastSpellL()
{
}
