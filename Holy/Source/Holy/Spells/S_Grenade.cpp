// Copyright Pizza Masters 5, All Rights Reserved.


#include "S_Grenade.h"

#include "DrawDebugHelpers.h"
#include "SpellProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Holy/Characters/Demon.h"

AS_Grenade::AS_Grenade()
{
	
}

void AS_Grenade::BeginPlay()
{
	Super::BeginPlay();
}

void AS_Grenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AS_Grenade::InitSpell(ADemon* demonRef)
{
	Super::InitSpell(demonRef);
}

void AS_Grenade::Cast()
{
	Super::Cast();

	const FVector spawnLocation = ProjectileSpawnOffset->GetComponentLocation();
	const FRotator spawnRotation = ProjectileSpawnOffset->GetComponentRotation();
	ASpellProjectile* projectile = GetWorld()->SpawnActor<ASpellProjectile>(SpellProjectile, spawnLocation, spawnRotation);
	
	const FVector spawnVelocity = Demon->GetControlRotation().Vector() + FVector(0, 0, 30);
	DrawDebugLine(GetWorld(), spawnLocation, spawnLocation + spawnVelocity * 50, FColor::Red, false, 5);
	projectile->GetProjectileMovement()->Velocity = spawnVelocity;
	projectile->InitProjectile(ProjectileData);
}
