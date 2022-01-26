// Copyright Pizza Masters 5, All Rights Reserved.


#include "SP_Grenade.h"

#include "Holy/Characters/Enemy.h"

ASP_Grenade::ASP_Grenade()
{
}

void ASP_Grenade::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);

	//if(OtherActor->GetClass()->IsChildOf<AEnemy>())
	if(Cast<AEnemy>(Hit.GetActor()))
	{
		UE_LOG(LogTemp, Warning, TEXT("OtherActor is %s, hitComponent is %s"), *GetNameSafe(Hit.GetActor()), *GetNameSafe(Hit.GetComponent()));
		AttachToActor(Hit.GetActor(), FAttachmentTransformRules::KeepWorldTransform); // Attach to hit actor and stays in position (sticky grenade)
	}
	else
	{
		Destroy();
	}
}
