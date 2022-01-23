// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Demon.generated.h"

class ASpell;
class AS_Spread;
class AS_Grenade;
class AS_Vacuum;
class AS_Water;
UCLASS()
class HOLY_API ADemon : public ACharacter
{
	GENERATED_BODY()
	
	ASpell* Spell_L;
	ASpell* Spell_R;

	AS_Spread* S_Spread;
	AS_Grenade* S_Grenade;
	AS_Vacuum* S_Vacuum;
	AS_Water* S_Water;
	
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

	void CastSpell_L();
	void CastSpell_R();
};
