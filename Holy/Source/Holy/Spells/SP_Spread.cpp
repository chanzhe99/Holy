// Copyright Pizza Masters 5, All Rights Reserved.


#include "SP_Spread.h"
#include "DrawDebugHelpers.h"
#include "Holy/Characters/Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"

ASP_Spread::ASP_Spread()
{

}

void ASP_Spread::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);
	AEnemy* hitEnemy = Cast<AEnemy>(OtherActor);
	ACharacter* character = Cast<ACharacter>(OtherActor);
	if (hitEnemy)
	{
		//OtherComp->AddImpulse(GetActorForwardVector()* KnockBackForce);
		UCharacterMovementComponent* cute = character->GetCharacterMovement();
		cute->AddImpulse(GetActorForwardVector() * KnockBackForce);
		hitEnemy->ApplyDamage(Damage);
	}

	DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 10, 4, FColor::Orange, false, 5);
}
