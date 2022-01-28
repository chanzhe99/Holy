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

private:
	float VacuumFlyTimer;
	bool IsSucking = false;
	float VacuumDuration;
	float VacuumInterval;
	//TArray<AActor*> suckingActors;

public:
	UPROPERTY(EditAnywhere, Category = SuckProperties)
	float VacuumFlyTimerMax = 0.0f;
	UPROPERTY(EditAnywhere, Category = SuckProperties)
	float VacuumDurationMax;
	UPROPERTY(EditAnywhere, Category = SuckProperties)
	float VacuumIntervalMax;
	UPROPERTY(EditAnywhere, Category = SuckProperties)
	TArray<AActor*> suckingActors;

private:
	void DoBigSuck(float deltaTime);
	void StopBigSuck();
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	virtual void BeginPlay()override;
	virtual void Tick(float deltaTime)override;
};
