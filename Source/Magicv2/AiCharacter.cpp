// Fill out your copyright notice in the Description page of Project Settings.


#include "AiCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Defendpoint.h"
#include "shockwave.h"
#include "MyCharacter.h"


// Sets default values
AAiCharacter::AAiCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Newbox =CreateDefaultSubobject<UBoxComponent>(TEXT("NewBox"));
	EnemyBeenHit = false;
	Health =100;
	CanAttack=false;
	
	GetCharacterMovement()->bOrientRotationToMovement =true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f,600.0f,0.0f);
	bUseControllerRotationPitch=false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	Damage = 10;
}

// Called when the game starts or when spawned
void AAiCharacter::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &AAiCharacter::OnOverlapBegin);
	Box->OnComponentEndOverlap.AddDynamic(this, &AAiCharacter::OnOverlapEnd);
}

// Called every frame
void AAiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(Damage >=100 )
	{
		Damage = 100;
	}

if (Health <= 0)
 	{
 		UWorld* const World = GetWorld();
 		const FVector BoxLocation = Box->GetComponentLocation();
 		const FRotator BoxRot = Box->GetComponentRotation();
 		World->SpawnActor<class AABaseItem>(BaseItem,BoxLocation,BoxRot);
 		
 		Destroy();}
	
	
}

void AAiCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	AMyCharacter* Char = Cast<AMyCharacter>(OtherActor);
	ADefendpoint* Defendpoint = Cast<ADefendpoint>(OtherActor);
	Ashockwave* ShockWave = Cast<Ashockwave>(OtherActor);
	if (Char)
	{
		Char->BeenHit =true;
		if(Char->PlayerShield ==true)
		{
			CanAttack =true;
			Char->Shield -= Damage;
		}else
		{
			CanAttack =true;
			Char->Health -=Damage;
		}}
	

	
	if(Defendpoint)
	{
	
		CanAttack =true;
	}
	
}

void AAiCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	AMyCharacter*Char =Cast<AMyCharacter>(OtherActor);
	ADefendpoint*Defendpoint =Cast<ADefendpoint>(OtherActor);
	if(Char)
	{
		Char->BeenHit =false;
		CanAttack =false;
		if(Char->BeenHit == false)
		{
			Char->SetTimer();
		}
	}
	if(Defendpoint)
	{
		CanAttack =false;
	}

	
}






