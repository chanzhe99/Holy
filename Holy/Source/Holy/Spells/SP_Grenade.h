// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpellProjectile.h"
#include "SP_Grenade.generated.h"

UCLASS()
class HOLY_API ASP_Grenade : public ASpellProjectile
{
	GENERATED_BODY()

	FTimerHandle GrenadeTimerHandle;
	UPROPERTY(EditAnywhere, Category = Attributes)
	float DetonationTime = 2.f;
	UPROPERTY(EditAnywhere, Category = Attributes)
	float ExplosionRadius = 500.f;
	
public:
	ASP_Grenade();
	virtual void InitProjectile(FVector desiredDirection) override;
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	UFUNCTION()
	void Explode();
};
