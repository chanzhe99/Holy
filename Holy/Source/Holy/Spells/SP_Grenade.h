// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpellProjectile.h"
#include "SP_Grenade.generated.h"

/**
 * 
 */
UCLASS()
class HOLY_API ASP_Grenade : public ASpellProjectile
{
	GENERATED_BODY()

public:
	ASP_Grenade();
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
};
