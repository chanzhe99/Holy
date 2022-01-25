// Copyright Pizza Masters 5, All Rights Reserved.


#include "SpellProjectile.h"
#include "Spell.h"
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
	/*MovementComponent->InitialSpeed = 3000.f;
	MovementComponent->MaxSpeed = 3000.f;*/
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
}

void ASpellProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	
}

void ASpellProjectile::InitProjectile(FProjectileData desiredData) const
{
	ProjectileMesh->SetStaticMesh(desiredData.mesh);
	ProjectileMesh->SetRelativeScale3D(desiredData.meshSize);
	ProjectileCollider->SetSphereRadius(desiredData.colliderRadius);
	ProjectileMovement->ProjectileGravityScale = desiredData.gravityScale;
}

