// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "MagicAttackBase.h"
#include "MyCharacter.h"

#include "NavigationSystemTypes.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root= CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(Root);

	Door= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(Root);

	NewBox = CreateDefaultSubobject<UBoxComponent>(TEXT("NewBox"));
	NewBox->SetupAttachment(Door);
	
	
	
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	NewBox->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnOverlapBegin);
	NewBox->OnComponentEndOverlap.AddDynamic(this, &ADoor::OnOverlapEnd);

	UE_LOG(LogTemp,Warning,TEXT("overlapped"));
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::DoorOpen()
{
}

void ADoor::SetDoor()
{
}

void ADoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning,TEXT("overlapped"));

	if(OtherActor)
	{
	    AMagicAttackBase* Fireballs =Cast<AMagicAttackBase>(OtherComp);
		
		AMyCharacter* Char = Cast<AMyCharacter>(OtherActor);
		if (Char)
		{
		
			if (Char->Money >= Price)
			{
				this->Destroy();
				Char->Money= Char->Money-Price;
			}
		}
		if(Fireballs)
		{
			Fireballs->Destroy();
		}
	}
	
}

void ADoor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
}



