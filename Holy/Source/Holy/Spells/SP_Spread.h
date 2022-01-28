// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpellProjectile.h"
#include "SP_Spread.generated.h"

/**
 * 
 */
UCLASS()
class HOLY_API ASP_Spread : public ASpellProjectile
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = Attributes)
	float KnockBackForce;
	UPROPERTY(EditAnywhere, Category = Attributes)
	int Damage;

public:
	ASP_Spread();
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
};
