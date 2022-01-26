// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpellProjectile.h"
#include "SP_Vacuum.generated.h"

/**
 * 
 */
UCLASS()
class HOLY_API ASP_Vacuum : public ASpellProjectile
{
	GENERATED_BODY()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
};
