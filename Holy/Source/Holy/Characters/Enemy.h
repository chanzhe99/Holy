// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UENUM()
enum E_EnemyStatus
{
	PIERCED		UMETA(DisplayName = "Pierced"),
	STICKIED	UMETA(DisplayName = "Stickied"),
	VACUUMED	UMETA(DisplayName = "Vacuumed"),
	DRENCHED	UMETA(DisplayName = "Wet"),
	ELECTRIFIED	UMETA(DisplayName = "Electrified")
};

UCLASS()
class HOLY_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	E_EnemyStatus EnemyStatus;
	AEnemy();

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	int EnemyHP;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void ApplyDamage(int damage);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Enemy")
	void SendDeathNotification();
};
