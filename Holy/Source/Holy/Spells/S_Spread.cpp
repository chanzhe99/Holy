// Copyright Pizza Masters 5, All Rights Reserved.


#include "S_Spread.h"
#include "DrawDebugHelpers.h"
#include "SpellProjectile.h"
#include "../Characters/Demon.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AS_Spread::AS_Spread()
{
	
}

void AS_Spread::BeginPlay()
{
	Super::BeginPlay();

	BulletAngle = FMath::DegreesToRadians(BulletAngle);
	Radius = BulletAngle * BulletDistance;
}

void AS_Spread::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AS_Spread::InitSpell(ADemon* demonRef)
{
	Super::InitSpell(demonRef);
}

void AS_Spread::Cast()
{
	Super::Cast();
	
	// This is not good, need discussion.
	FVector bulletVector;
	FVector cameraTransform = Demon->Camera->GetComponentTransform().GetLocation();
	FVector cameraForward = Demon->Camera->GetForwardVector();
	FVector cameraRight = Demon->Camera->GetRightVector();
	FVector cameraUp = Demon->Camera->GetUpVector();

	for (int i = 0; i <= PalletCount; i++)
	{
		//Randomizes a vector for a bullet
		bulletVector = CalculatePalletSpread(Radius);

		//Determine an endpoint of the vector.
		FVector endPoint = (cameraTransform + cameraForward * BulletDistance) + // camera plus bullet fly distance.
						   (cameraRight * bulletVector.X) + // offset the bullet on X axis
						   (cameraUp * bulletVector.Y);     // offest the bullet on Y axis

        //Raycasts to the vector.
		FHitResult hit;
		FCollisionQueryParams CollisionParams;
		GetWorld()->LineTraceSingleByChannel(
			hit,
			cameraTransform,
			endPoint, 
			ECC_WorldDynamic,
			CollisionParams);

		//Debug Line.
		DrawDebugLine(GetWorld(), cameraTransform, endPoint, FColor::Green, false, 2.f, false, 4.f);

		//Spawn it
		SpawnPellet(endPoint);
	}
}

FVector AS_Spread::CalculatePalletSpread(float radius)
{
	float angle;
	angle = FMath::RandRange(0.0f, 360.0f);
	angle = FMath::DegreesToRadians(angle);

	float distanceFromCenter;
	distanceFromCenter = FMath::RandRange(0.0f, radius);

	FVector returnPoint;
	float cosDegree = FMath::Cos(angle);
	float sinDegree = FMath::Sin(angle);

	returnPoint.X = cosDegree * distanceFromCenter;
	returnPoint.Y = sinDegree * distanceFromCenter;

	return returnPoint;
}

void AS_Spread::SpawnPellet(FVector endVector)
{
	const FRotator SpawnRotation = Demon->GetControlRotation();
	// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	const FVector SpawnLocation = Demon->Spell_R_SpawnOffset->GetComponentLocation();
	// ^This one need to add gun muzzle offset, spawning at Player location will cause collision with player if collision with pawn channel is turned on

	ASpellProjectile* bullet = GetWorld()->SpawnActor<ASpellProjectile>(SpellProjectile, SpawnLocation, SpawnRotation);

	FVector direction = endVector - bullet->GetActorLocation();
	direction = direction.GetSafeNormal();
	bullet->InitProjectile(direction);
	//bullet->ProjectileMovement->Velocity = direction * 100;
}