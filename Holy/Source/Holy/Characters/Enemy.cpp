// Copyright Pizza Masters 5, All Rights Reserved.


#include "Enemy.h"

#include "DrawDebugHelpers.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::ApplyDamage(int damage)
{
	EnemyHP -= FMath::Abs(damage);
		
	const FString debugString = FString::Printf(TEXT("Taken Damage: %d\n Remaining HP: %d"), damage, EnemyHP);
	DrawDebugString(GetWorld(), GetActorLocation() + FVector(0, 0, 100), debugString, 0, FColor::Orange, 3);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
	
	if (EnemyHP <= 0)
		SendDeathNotification();
}

void AEnemy::SendDeathNotification_Implementation()
{

}
