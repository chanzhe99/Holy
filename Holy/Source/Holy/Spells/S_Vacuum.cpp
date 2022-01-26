// Copyright Pizza Masters 5, All Rights Reserved.


#include "S_Vacuum.h"
#include "../Characters/Demon.h"
#include "Camera/CameraComponent.h"
#include "SpellProjectile.h"

AS_Vacuum::AS_Vacuum()
{

}

void AS_Vacuum::BeginPlay()
{
	Super::BeginPlay();
}

void AS_Vacuum::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AS_Vacuum::InitSpell(ADemon* demonRef)
{
	Super::InitSpell(demonRef);
}

void AS_Vacuum::Cast()
{
	Super::Cast();
	SpawnSuck();
}

void AS_Vacuum::SpawnSuck()
{
	const FRotator SpawnRotation = Demon->GetControlRotation();
	// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	const FVector SpawnLocation = Demon->Spell_R_SpawnOffset->GetComponentLocation();
	// ^This one need to add gun muzzle offset, spawning at Player location will cause collision with player if collision with pawn channel is turned on

	ASpellProjectile* bullet = GetWorld()->SpawnActor<ASpellProjectile>(SpellProjectile, SpawnLocation, SpawnRotation);

	FVector direction = Demon->Camera->GetForwardVector();
	bullet->InitProjectile(direction);
}