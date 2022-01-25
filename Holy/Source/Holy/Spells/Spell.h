// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spell.generated.h"

USTRUCT()
struct FProjectileData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMesh* mesh;
	UPROPERTY(EditAnywhere)
	FVector meshSize;
	UPROPERTY(EditAnywhere)
	float colliderRadius;
	UPROPERTY(EditAnywhere)
	float speed;
	UPROPERTY(EditAnywhere)
	float gravityScale;
};

UCLASS()
class HOLY_API ASpell : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = Mesh)
	UStaticMeshComponent* SpellMesh;
	
	UPROPERTY(EditAnywhere, Category = Spell)
	UAnimationAsset* SpellAnim_L;
	UPROPERTY(EditAnywhere, Category = Spell)
	UAnimationAsset* SpellAnim_R;

	UPROPERTY(EditDefaultsOnly, Category = Spell)
	TSubclassOf<class ASpellProjectile> SpellProjectile;

	bool IsOnLeftArm = true;
	UPROPERTY(EditAnywhere, Category = Spell)
	float SpellCD = 1.f;
	UPROPERTY(EditAnywhere, Category = Spell)
	float SpellCD_Count = SpellCD;
	UPROPERTY()
	class ADemon* Demon;
	UPROPERTY()
	USceneComponent* ProjectileSpawnOffset;
	FProjectileData ProjectileData;
	
public:
	ASpell();
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void InitSpell(ADemon* demonRef);
	virtual void AttachSpell(bool attachToLeftArm);
	virtual void Cast();
};
