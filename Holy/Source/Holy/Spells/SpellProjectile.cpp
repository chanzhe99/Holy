// Copyright Pizza Masters 5, All Rights Reserved.


#include "SpellProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ASpellProjectile::ASpellProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileCollider = CreateDefaultSubobject<USphereComponent>("ProjectileCollider");
	ProjectileCollider->InitSphereRadius(5.f);
	ProjectileCollider->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileCollider->OnComponentHit.AddDynamic(this, &ASpellProjectile::OnHit);
	ProjectileCollider->SetupAttachment(RootComponent);
	
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMesh->SetupAttachment(ProjectileCollider);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	ProjectileMovement->UpdatedComponent = ProjectileCollider;
	ProjectileMovement->bRotationFollowsVelocity = true;
}

void ASpellProjectile::InitProjectile(FVector desiredDirection)
{
	ProjectileMovement->Velocity = desiredDirection * ProjectileSpeed;
	//ProjectileMovement->InitialSpeed = ProjectileSpeed;
}

void ASpellProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
}
