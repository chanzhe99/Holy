// Copyright Pizza Masters 5, All Rights Reserved.


#include "SP_Grenade.h"
#include "Holy/Characters/Enemy.h"

ASP_Grenade::ASP_Grenade()
{
	ProjectileSpeed = 300;
}

void ASP_Grenade::InitProjectile(FVector desiredDirection)
{
	Super::InitProjectile(desiredDirection);

	GetWorldTimerManager().SetTimer(GrenadeTimerHandle, this, &ASP_Grenade::Explode, 3, false);
}

void ASP_Grenade::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);

	AttachToActor(Hit.GetActor(), FAttachmentTransformRules::KeepWorldTransform); // Attach to hit actor and stays in position (sticky grenade)
	if(Cast<AEnemy>(Hit.GetActor()))
	{
		UE_LOG(LogTemp, Warning, TEXT("OtherActor is %s, hitComponent is %s"), *GetNameSafe(Hit.GetActor()), *GetNameSafe(Hit.GetComponent()));
	}
}

void ASP_Grenade::Explode()
{
	// Do damage to enemies w/ SphereCast
	// Play VFX
	Destroy();
	GetWorldTimerManager().ClearTimer(GrenadeTimerHandle);
}
