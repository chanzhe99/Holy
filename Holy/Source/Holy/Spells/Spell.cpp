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

	if(SpellCD_Count < SpellCD)
		SpellCD_Count += DeltaTime;
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
	IsOnLeftArm = attachToLeftArm;
	if (IsOnLeftArm)
	{
		Demon->Spell_L = this;
		AttachToActor(Demon, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Spell_L");
		UE_LOG(LogTemp, Warning, TEXT("%s attached to Left Arm"), *GetNameSafe(this));
	}
	else
	{
		Demon->Spell_R = this;
		AttachToActor(Demon, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Spell_R");
		UE_LOG(LogTemp, Warning, TEXT("%s attached to Right Arm"), *GetNameSafe(this));
	}
}

void ASpell::Cast()
{
	if(SpellCD_Count >= SpellCD)
	{
		SpellCD_Count = 0;
		const FString debugString = FString::Printf(TEXT("%s casted"), *GetNameSafe(this));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, debugString);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
	}
	else
	{
		const FString debugString = FString::Printf(TEXT("%s is on CD"), *GetNameSafe(this));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, debugString);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *debugString);
	}
}

