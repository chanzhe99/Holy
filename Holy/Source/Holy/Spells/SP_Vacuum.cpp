// Copyright Pizza Masters 5, All Rights Reserved.


#include "SP_Vacuum.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

void ASP_Vacuum::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);
}

void ASP_Vacuum::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;
	Super::BeginPlay();
}

void ASP_Vacuum::DoBigSuck(float deltaTime)
{
	VacuumInterval += deltaTime;
	
	if (VacuumInterval > VacuumIntervalMax)
	{
		VacuumInterval = 0.0f;
	}
	else
	{
		return;
	}

	FCollisionQueryParams CollisionParams;

	FCollisionShape MySphere = FCollisionShape::MakeSphere(500.0f); // 5M Radius
	TArray<FHitResult> OutResults;

	// Ignore any specific actors
	TArray<AActor*> ignoreActors;
	// Ignore self or remove this line to not ignore any
	ignoreActors.Init(this, 1);

	UKismetSystemLibrary::SphereTraceMulti(GetWorld(), GetActorLocation(), GetActorLocation() + FVector::OneVector * 0.001, MySphere.GetSphereRadius(),
		ETraceTypeQuery::TraceTypeQuery1, false, ignoreActors, EDrawDebugTrace::ForDuration, OutResults, true);


	for (FHitResult& hit : OutResults)
	{
		UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>((hit.GetActor())->GetRootComponent());

		if (MeshComp)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *hit.GetActor()->GetName());

			MeshComp->AddRadialImpulse(GetActorLocation(), 500.f, -200000.f, ERadialImpulseFalloff::RIF_Constant, false);
			
			if (!suckingActors.Contains(hit.GetActor()))
			{
				suckingActors.Add(hit.GetActor());
			}
		}
	}
}

void ASP_Vacuum::StopBigSuck()
{
	for (AActor* Actor : suckingActors)
	{
		Actor->GetVelocity() = FVector::ZeroVector;
	}
}

void ASP_Vacuum::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (IsSucking)
	{
		if (VacuumDuration < VacuumDurationMax)
		{
			DoBigSuck(deltaTime);
			VacuumDuration += deltaTime;
		}
		else
		{
			IsSucking = false;
			VacuumDuration = 0.0f;
			StopBigSuck();
			Destroy();
			//UE_LOG(LogTemp, Warning, TEXT("Stop sucking"));
		}
	}
	else
	{
		if (VacuumFlyTimer < VacuumFlyTimerMax)
		{
			VacuumFlyTimer += deltaTime;
		}
		else
		{
			IsSucking = true;
			VacuumFlyTimer = 0;
			//UE_LOG(LogTemp, Warning, TEXT("Start Sucking"));
			ProjectileMovement->StopMovementImmediately();
		}
	}
}
