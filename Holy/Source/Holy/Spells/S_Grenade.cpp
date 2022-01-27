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

void AS_Grenade::Cast()
{
	Super::Cast();

	const FVector spawnLocation = ProjectileSpawnOffset->GetComponentLocation();
	const FRotator spawnRotation = ProjectileSpawnOffset->GetComponentRotation();
	const FVector spawnDirection = Demon->GetControlRotation().Vector();
	ASpellProjectile* projectile = GetWorld()->SpawnActor<ASpellProjectile>(SpellProjectile, spawnLocation, spawnRotation);
	projectile->InitProjectile(spawnDirection);
	
	DrawDebugLine(GetWorld(), spawnLocation, spawnLocation + spawnDirection * 500, FColor::Red, false, 5);
}
