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
}

void ADemon::BeginPlay()
{
	Super::BeginPlay();

	if(IsValid(BPS_Spread))
	{
		S_Spread = GetWorld()->SpawnActor<AS_Spread>(BPS_Spread);
		S_Spread->InitSpell(this);	
	}
	else
	{
		const FString debugString = FString(TEXT("BPS_Spread BP class not found in Demon BP, please fill in BPS_Spread in Demon BP"));
		GEngine->AddOnScreenDebugMessage(96, 999.f, FColor::Red, debugString);
		UE_LOG(LogTemp, Error, TEXT("%s"), *debugString);
	}

	if(IsValid(BPS_Grenade))
	{
		S_Grenade = GetWorld()->SpawnActor<AS_Grenade>(BPS_Grenade);
		S_Grenade->InitSpell(this);
	}
	else
	{
		const FString debugString = FString(TEXT("BPS_Grenade BP class not found in Demon BP, please fill in BPS_Grenade in Demon BP"));
		GEngine->AddOnScreenDebugMessage(97, 999.f, FColor::Red, debugString);
		UE_LOG(LogTemp, Error, TEXT("%s"), *debugString);
	}

	if(IsValid(BPS_Vacuum))
	{
		S_Vacuum = GetWorld()->SpawnActor<AS_Vacuum>(BPS_Vacuum);
		S_Vacuum->InitSpell(this);
	}
	else
	{
		const FString debugString = FString(TEXT("BPS_Vacuum BP class not found in Demon BP, please fill in BPS_Vacuum in Demon BP"));
		GEngine->AddOnScreenDebugMessage(98, 999.f, FColor::Red, debugString);
		UE_LOG(LogTemp, Error, TEXT("%s"), *debugString);
	}

	if(IsValid(BPS_Water))
	{
		S_Water = GetWorld()->SpawnActor<AS_Water>(BPS_Water);
		S_Water->InitSpell(this);
	}
	else
	{
		const FString debugString = FString(TEXT("BPS_Water BP class not found in Demon BP, please fill in BPS_Water in Demon BP"));
		GEngine->AddOnScreenDebugMessage(99, 9999.f, FColor::Red, debugString);
		UE_LOG(LogTemp, Error, TEXT("%s"), *debugString);
	}

	if(S_Spread)
		S_Spread->AttachSpell(true);
	if(S_Grenade)
		S_Grenade->AttachSpell(false);
}

void ADemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	if(Spell_L)
		Spell_L->Cast();
}

void ADemon::CastSpell_R() const
{
	if(Spell_R)
		Spell_R->Cast();
}
