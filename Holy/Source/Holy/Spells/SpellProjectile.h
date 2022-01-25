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

public:
	ASpellProjectile();
	
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
	void InitProjectile(struct FProjectileData desiredData) const;
};
