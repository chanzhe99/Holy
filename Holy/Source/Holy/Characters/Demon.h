// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Demon.generated.h"

UCLASS()
class HOLY_API ADemon : public ACharacter
{
	GENERATED_BODY()

private:
	
	
public:
	// Sets default values for this character's properties
	ADemon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Look_X(float Value);
	void Look_Y(float Value);
	void Move_X(float Value);
	void Move_Y(float Value);

	void CastSpellL();
};
