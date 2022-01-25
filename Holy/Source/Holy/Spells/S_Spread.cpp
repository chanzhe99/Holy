// Copyright Pizza Masters 5, All Rights Reserved.


#include "S_Spread.h"
#include "DrawDebugHelpers.h"
#include "SpellProjectile.h"
#include "../Characters/Demon.h"
#include "Camera/CameraComponent.h"

AS_Spread::AS_Spread()
{
	
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

void AS_Spread::BeginPlay()
{
	Super::BeginPlay();
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
	UE_LOG(LogTemp, Warning, TEXT("Shotgun is shoot"));
	FVector bulletVector;
	for (int i = 0; i <= PalletCount; i++)
	{
		bulletVector = CalculatePalletSpread(Radius);
		FHitResult hit;
		// These dont have to be in for loop
		FVector cameraTransform = Demon->Camera->GetComponentTransform().GetLocation();
		FVector cameraForward = Demon->Camera->GetForwardVector();
		FVector cameraRight = Demon->Camera->GetRightVector();
		FVector cameraUp = Demon->Camera->GetUpVector();
		//
		FVector endPoint = (cameraTransform + cameraForward * BulletDistance) + (cameraRight * bulletVector.X) + (cameraUp * bulletVector.Y);
		FCollisionQueryParams CollisionParams;

		GetWorld()->LineTraceSingleByChannel(
			hit,
			cameraTransform,
			(cameraTransform + cameraForward * BulletDistance) + (cameraRight * bulletVector.X) + (cameraUp * bulletVector.Y), // can use endPoint var for this
			ECC_WorldDynamic,
			CollisionParams);

		DrawDebugLine(GetWorld(), cameraTransform, (cameraTransform + cameraForward * BulletDistance) + (cameraRight * bulletVector.X) + (cameraUp * bulletVector.Y), FColor::Green, false, 2.f, false, 4.f);

		const FRotator SpawnRotation = Demon->GetControlRotation();
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = Demon->GetActorLocation(); /*+ SpawnRotation.RotateVector(GunOffset);*/
		// ^This one need to add gun muzzle offset, spawning at Player location will cause collision with player if collision with pawn channel is turned on

		//Set Spawn Collision Handling Override
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		// spawn the projectile at the muzzle
		UE_LOG(LogTemp, Warning, TEXT("Spawning Shotgun Pallet"));
		AActor* bullet = GetWorld()->SpawnActor<ASpellProjectile>(SpellProjectile, SpawnLocation, SpawnRotation);

		FVector direction = endPoint - bullet->GetActorLocation();
		direction = direction.GetSafeNormal();
		//bullet->FindComponentByClass<UProjectileMovementComponent>()->SetVelocityInLocalSpace(direction * 1);
		//bullet->FindComponentByClass<UPrimitiveComponent>()->AddImpulse(endPoint * 10);
	}
}
