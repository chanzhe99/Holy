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

	UPROPERTY(EditAnywhere, Category = Spells)
	TSubclassOf<AS_Spread> BPS_Spread;
	UPROPERTY()
	AS_Spread* S_Spread;
	UPROPERTY(EditAnywhere, Category = Spells)
	TSubclassOf<AS_Grenade> BPS_Grenade;
	UPROPERTY()
	AS_Grenade* S_Grenade;
	UPROPERTY(EditAnywhere, Category = Spells)
	TSubclassOf<AS_Vacuum> BPS_Vacuum;
	UPROPERTY()
	AS_Vacuum* S_Vacuum;
	UPROPERTY(EditAnywhere, Category = Spells)
	TSubclassOf<AS_Water> BPS_Water;
	UPROPERTY()
	AS_Water* S_Water;
	
public:
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* ArmMesh_L;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* ArmMesh_R;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Spell_L_SpawnOffset;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Spell_R_SpawnOffset;
	
	UPROPERTY(VisibleAnywhere, Category = Spells)
	ASpell* Spell_L;
	UPROPERTY(VisibleAnywhere, Category = Spells)
	ASpell* Spell_R;

	ADemon();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void Look_X(float Value);
	void Look_Y(float Value);
	void Move_X(float Value);
	void Move_Y(float Value);

	void CastSpell_L() const;
	void CastSpell_R() const;
};
