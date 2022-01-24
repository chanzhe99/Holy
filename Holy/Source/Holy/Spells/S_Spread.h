// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "S_Spread.generated.h"

UCLASS()
class HOLY_API AS_Spread : public ASpell
{
	GENERATED_BODY()
	
public:
	AS_Spread();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void InitSpell(ADemon* demonRef) override;
	virtual void Cast() override;
};
