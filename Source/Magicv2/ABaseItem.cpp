// Fill out your copyright notice in the Description page of Project Settings.


#include "ABaseItem.h"

#include "AiCharacter.h"
#include "MyCharacter.h"

// Sets default values
AABaseItem::AABaseItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NEWCollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	NEWCollisionVolume->SetGenerateOverlapEvents(true);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = NEWCollisionVolume;
}
// Called when the game starts or when spawned
void AABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
	NEWCollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AABaseItem::OnOverlapBegin);
	NEWCollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AABaseItem::OnOverlapEnd);
	
	
}


// Called every frame
void AABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABaseItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if(OtherActor)
	{
		AMyCharacter* Char = Cast<AMyCharacter>(OtherActor);
	
		if (Char)
		{
			Char->Money += 10;
			this->Destroy();
			
			UE_LOG(LogTemp, Warning, TEXT("pickedup"))
		}
	}
	
}

void AABaseItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	
}


