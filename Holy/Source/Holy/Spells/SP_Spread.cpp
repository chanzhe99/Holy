// Copyright Pizza Masters 5, All Rights Reserved.


#include "SP_Spread.h"

#include "DrawDebugHelpers.h"

ASP_Spread::ASP_Spread()
{

}

void ASP_Spread::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);

	DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 10, 4, FColor::Orange, false, 5);
}
