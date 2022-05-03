// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlocker.h"



#include "AiCharacter.h"
#include "MyCharacter.h"

// Sets default values
AMyBlocker::AMyBlocker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NEWCollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionVolume"));
	NEWCollisionVolume->SetGenerateOverlapEvents(true);
}



// Called when the game starts or when spawned
void AMyBlocker::BeginPlay()
{
	Super::BeginPlay();
	NEWCollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AMyBlocker::OnOverlapBegin);
	NEWCollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AMyBlocker::OnOverlapEnd);
	
}

// Called every frame
void AMyBlocker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyBlocker::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		AMyCharacter* Mychar = Cast<AMyCharacter>(OtherActor);
		AAiCharacter* Enemy =Cast<AAiCharacter>(OtherActor);
		if(Mychar)
		{
			UE_LOG(LogTemp,Error,TEXT("overlapped"));
		}
		if(Enemy)
		{
			NEWCollisionVolume->SetGenerateOverlapEvents(false);
		}
		
	}
	
}

void AMyBlocker::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
}
