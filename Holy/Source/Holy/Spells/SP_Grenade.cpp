// Copyright Pizza Masters 5, All Rights Reserved.


#include "SP_Grenade.h"

ASP_Grenade::ASP_Grenade()
{
}

void ASP_Grenade::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                        FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);

	AttachToActor(OtherActor, FAttachmentTransformRules::KeepRelativeTransform); // Attach to hit actor and stays in position (sticky grenade)
}
