// Copyright Pizza Masters 5, All Rights Reserved.


#include "Spell.h"
#include "Holy/Characters/Demon.h"

ASpell::ASpell()
{
	PrimaryActorTick.bCanEverTick = true;

	SpellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spell Mesh"));
	SpellMesh->SetupAttachment(RootComponent);
}

void ASpell::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("%s - Tick"), *GetNameSafe(this));

	if(CD_Count < CD)
		CD_Count += DeltaTime;
}

void ASpell::InitSpell(ADemon* demonRef)
{
	SetActorTickEnabled(false);
	SetActorLocation(FVector(0, 0, -4000));
	Demon = demonRef;
}

void ASpell::AttachSpell(bool attachToLeftArm)
{
	SetActorTickEnabled(true);
	CD_Count = CD;
	IsOnLeftArm = attachToLeftArm;
	if (IsOnLeftArm)
	{
		Demon->Spell_L = this;
		ProjectileSpawnOffset = Demon->Spell_L_SpawnOffset;
		AttachToActor(Demon, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Spell_L");
		//UE_LOG(LogTemp, Warning, TEXT("%s attached to Left Arm"), *GetNameSafe(this));
	}
	else
	{
		Demon->Spell_R = this;
		ProjectileSpawnOffset = Demon->Spell_R_SpawnOffset;
		AttachToActor(Demon, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Spell_R");
		//UE_LOG(LogTemp, Warning, TEXT("%s attached to Right Arm"), *GetNameSafe(this));
	}
}

void ASpell::Cast()
{
	const FString debugString = FString::Printf(TEXT("%s casted"), *GetNameSafe(this));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, debugString);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
}
