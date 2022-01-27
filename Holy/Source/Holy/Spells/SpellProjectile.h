// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpellProjectile.generated.h"

UCLASS()
class HOLY_API ASpellProjectile : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Components)
	class USphereComponent* ProjectileCollider;
	UPROPERTY(EditAnywhere, Category = Components)
	UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(EditAnywhere, Category = Components)
	class UProjectileMovementComponent* ProjectileMovement;

protected:
	UPROPERTY(EditAnywhere, Category = ProjectileData)
	float ProjectileSpeed = 1;

public:
	ASpellProjectile();
	
	virtual void InitProjectile(FVector desiredDirection);
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
