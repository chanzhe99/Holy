// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "S_Spread.generated.h"

UCLASS()
class HOLY_API AS_Spread : public ASpell
{
	GENERATED_BODY()
	
public : 
	//Shotgun Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float BulletAngle = 5.0f; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float StartingBulletAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float BulletDistance = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		int PalletCount = 10;

public:
	AS_Spread();

private:
	FVector CalculatePalletSpread(float radius);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void InitSpell(ADemon* demonRef) override;
	virtual void Cast() override;

};
