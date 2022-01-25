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
	class USphereComponent* Collider;
	UPROPERTY(EditAnywhere, Category = Components)
	class UStaticMeshComponent* Mesh;

	
public:
	UPROPERTY(EditAnywhere, Category = Components)
	class UProjectileMovementComponent* MovementComponent;
	
	// Sets default values for this actor's properties
	ASpellProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
