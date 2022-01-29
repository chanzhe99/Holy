// Copyright Pizza Masters 5, All Rights Reserved.


#include "Demon.h"
#include "Camera/CameraComponent.h"
#include "Holy/Spells/Spell.h"
#include "Holy/Spells/S_Spread.h"
#include "Holy/Spells/S_Grenade.h"
#include "Holy/Spells/S_Vacuum.h"
#include "Holy/Spells/S_Water.h"

ADemon::ADemon()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create a camera component
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	Camera->bUsePawnControlRotation = true;

	// Create hand meshes
	ArmMesh_L = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ArmMesh_Left"));
	ArmMesh_L->SetupAttachment(Camera);
	ArmMesh_L->CastShadow = false;
	ArmMesh_R = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ArmMesh_Right"));
	ArmMesh_R->SetupAttachment(Camera);
	ArmMesh_R->CastShadow = false;

	Spell_L_SpawnOffset = CreateDefaultSubobject<USceneComponent>(TEXT("Spell_L_SpawnOffset"));
	Spell_L_SpawnOffset->SetupAttachment(ArmMesh_L);
	Spell_R_SpawnOffset = CreateDefaultSubobject<USceneComponent>(TEXT("Spell_R_SpawnOffset"));
	Spell_R_SpawnOffset->SetupAttachment(ArmMesh_R);
}

void ADemon::BeginPlay()
{
	Super::BeginPlay();

	switch (SpellType_L)
	{
	case E_SpellType::SPREAD:
		SpawnAndAttachSpell(BPS_Spread, Spell_L, Spell_L_SpawnOffset, true);
		break;
	case E_SpellType::GRENADE:
		SpawnAndAttachSpell(BPS_Grenade, Spell_L, Spell_L_SpawnOffset, true);
		break;
	case E_SpellType::VACUUM:
		SpawnAndAttachSpell(BPS_Vacuum, Spell_L, Spell_L_SpawnOffset, true);
		break;
	case E_SpellType::WATER:
		SpawnAndAttachSpell(BPS_Water, Spell_L, Spell_L_SpawnOffset, true);
		break;
	}

	switch (SpellType_R)
	{
	case E_SpellType::SPREAD:
		SpawnAndAttachSpell(BPS_Spread, Spell_R, Spell_R_SpawnOffset, true);
		break;
	case E_SpellType::GRENADE:
		SpawnAndAttachSpell(BPS_Grenade, Spell_R, Spell_R_SpawnOffset, true);
		break;
	case E_SpellType::VACUUM:
		SpawnAndAttachSpell(BPS_Vacuum, Spell_R, Spell_R_SpawnOffset, true);
		break;
	case E_SpellType::WATER:
		SpawnAndAttachSpell(BPS_Water, Spell_R, Spell_R_SpawnOffset, true);
		break;
	}

}

void ADemon::SendGotHitNotification_Implementation(int damageTaken)
{
}

void ADemon::SendDeathNotification_Implementation()
{
}

void ADemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADemon::SpawnAndAttachSpell(TSubclassOf<ASpell> spellToSpawn, ASpell*& spellAttachHand, USceneComponent* projectileOffsetComp, bool isLeftArm)
{
	if(IsValid(spellToSpawn))
	{
		spellAttachHand = GetWorld()->SpawnActor<ASpell>(spellToSpawn);
		spellAttachHand->InitSpell(this, projectileOffsetComp, isLeftArm);
	}
	else
	{
		const FString debugString = FString::Printf(TEXT("%s BP class reference not found in Demon BP"), *GetNameSafe(spellToSpawn));
		GEngine->AddOnScreenDebugMessage(96, 999.f, FColor::Red, debugString);
		UE_LOG(LogTemp, Error, TEXT("%s"), *debugString);
	}
}

void ADemon::Look_X(float Value)
{
	AddControllerYawInput(Value);
}

void ADemon::Look_Y(float Value)
{
	AddControllerPitchInput(Value);
}

void ADemon::Move_X(float Value)
{
	if (Value != 0)
		AddMovementInput(GetActorForwardVector(), Value);
}

void ADemon::Move_Y(float Value)
{
	if (Value != 0)
		AddMovementInput(GetActorRightVector(), Value);
}

void ADemon::CastSpell_L() const
{
	if(Spell_L->CD_Count >= Spell_L->CD)
	{
		Spell_L->CD_Count = 0;
		Spell_L->Cast();
	}
	else
	{
		const FString debugString = FString::Printf(TEXT("%s is on CD"), *GetNameSafe(Spell_L));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, debugString);
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
	}
}

void ADemon::CastSpell_R() const
{
	if(Spell_R->CD_Count >= Spell_R->CD)
	{
		Spell_R->CD_Count = 0;
		Spell_R->Cast();
	}
	else
	{
		const FString debugString = FString::Printf(TEXT("%s is on CD"), *GetNameSafe(Spell_R));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, debugString);
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
	}
}

void ADemon::ApplyDamage_Implementation(int damage)
{
	int hpBeforeDeduction = CurrentHP;
	CurrentHP -= FMath::Abs(damage);

	if (CurrentHP <= 0)
		SendDeathNotification();
	else
	{
		int hpDifference = (damage < hpBeforeDeduction) ? (damage) : (hpBeforeDeduction);
		SendGotHitNotification(hpDifference);
	}
}
