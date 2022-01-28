// Copyright Pizza Masters 5, All Rights Reserved.


#include "SP_Grenade.h"

#include "DrawDebugHelpers.h"
#include "Holy/Characters/Enemy.h"

ASP_Grenade::ASP_Grenade()
{
	ProjectileSpeed = 300;
}

void ASP_Grenade::InitProjectile(FVector desiredDirection)
{
	Super::InitProjectile(desiredDirection);

	GetWorldTimerManager().SetTimer(GrenadeTimerHandle, this, &ASP_Grenade::Explode, DetonationTime, false);
}

void ASP_Grenade::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);

	SetActorEnableCollision(false);
	
	AttachToActor(Hit.GetActor(), FAttachmentTransformRules::KeepWorldTransform); // Attach to hit actor and stays in position (sticky grenade)
	if(Cast<AEnemy>(Hit.GetActor()))
	{
		UE_LOG(LogTemp, Warning, TEXT("OtherActor is %s, hitComponent is %s"), *GetNameSafe(Hit.GetActor()), *GetNameSafe(Hit.GetComponent()));
	}
}

void ASP_Grenade::Explode()
{
	UE_LOG(LogTemp, Warning, TEXT("Explode called"));
	GetWorldTimerManager().ClearTimer(GrenadeTimerHandle);
	// Do damage to enemies w/ SphereCast
	TArray<FHitResult> outHits;
	FCollisionShape collisionSphere = FCollisionShape::MakeSphere(ExplosionRadius);
	DrawDebugSphere(GetWorld(), GetActorLocation(), collisionSphere.GetSphereRadius(), 16, FColor::Orange, false, 3);
	bool isHit = GetWorld()->SweepMultiByObjectType(outHits, GetActorLocation(), GetActorLocation() + FVector::OneVector * 0.1f, FQuat::Identity, ECC_GameTraceChannel2, collisionSphere);

	if(isHit)
	{
		/*for (int i = 0; i < outHits.Num(); ++i)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s (%d) was hit"), *GetNameSafe(outHits[i].GetActor()), i);
		}*/
		for (auto hitResult : outHits)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s was hit"), *GetNameSafe(hitResult.GetActor()));
			AEnemy* hitEnemy = Cast<AEnemy>(hitResult.GetActor());
			if (hitEnemy)
				hitEnemy->ApplyDamage(2);
		}
	}
	
	// Play VFX
	Destroy();
}
