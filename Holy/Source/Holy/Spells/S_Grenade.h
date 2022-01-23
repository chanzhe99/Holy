// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "S_Grenade.generated.h"

UCLASS()
class HOLY_API AS_Grenade : public ASpell
{
	GENERATED_BODY()

public:
	AS_Grenade();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void InitSpell() override;
	virtual void Cast() override;
};
