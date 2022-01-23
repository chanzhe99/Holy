// Copyright Pizza Masters 5, All Rights Reserved.


#include "Demon.h"
#include "Holy/Spells/Spell.h"
#include "Holy/Spells/S_Spread.h"
#include "Holy/Spells/S_Grenade.h"
#include "Holy/Spells/S_Vacuum.h"
#include "Holy/Spells/S_Water.h"

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

	S_Spread = GetWorld()->SpawnActor<AS_Spread>();
	S_Spread->InitSpell();
	
	S_Grenade = GetWorld()->SpawnActor<AS_Grenade>();
	S_Grenade->InitSpell();
	
	S_Vacuum = GetWorld()->SpawnActor<AS_Vacuum>();
	S_Vacuum->InitSpell();
	
	S_Water = GetWorld()->SpawnActor<AS_Water>();
	S_Water->InitSpell();
	
	S_Spread->SetActorTickEnabled(true);
	Spell_L = S_Spread;
	Spell_L->AttachToActor(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	if(Spell_L)
		UE_LOG(LogTemp, Warning, TEXT("Spell_L spawned"));

	S_Grenade->SetActorTickEnabled(true);
	Spell_R = S_Grenade;
	Spell_R->AttachToActor(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	if(Spell_R)
		UE_LOG(LogTemp, Warning, TEXT("Spell_R spawned"));
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

void ADemon::CastSpell_L()
{
	if(Spell_L)
		Spell_L->Cast();
}

void ADemon::CastSpell_R()
{
	if(Spell_R)
		Spell_R->Cast();
}
