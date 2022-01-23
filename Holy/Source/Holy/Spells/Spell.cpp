// Copyright Pizza Masters 5, All Rights Reserved.


 #include "Spell.h"

// Sets default values
ASpell::ASpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spell Mesh"));
	SpellMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("%s - Tick"), *GetNameSafe(this));
}

void ASpell::InitSpell()
{
	SetActorTickEnabled(false);
	SetActorLocation(FVector(0, 0, -4000));
}

void ASpell::Cast()
{
	UE_LOG(LogTemp, Warning, TEXT("%s casted"), *GetNameSafe(this));
	const FString string = FString::Printf(TEXT("Spell - %s"), *GetNameSafe(this));
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, string);
	
}

