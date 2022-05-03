// Fill out your copyright notice in the Description page of Project Settings.

#include "AiCharacter.h"
#include "shockwave.h"

// Sets default values
Ashockwave::Ashockwave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	NewCoillions = CreateDefaultSubobject<USphereComponent>(TEXT("NewCollsion"));
	NewCoillions->SetGenerateOverlapEvents(true);
	NewCoillions->BodyInstance.SetCollisionProfileName("Projectile");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	
	
}

// Called when the game starts or when spawned
void Ashockwave::BeginPlay()
{
	Super::BeginPlay();
	NewCoillions->OnComponentBeginOverlap.AddDynamic(this, &Ashockwave::OnOverlapBegin);
	NewCoillions->OnComponentEndOverlap.AddDynamic(this, &Ashockwave::OnOverlapEnd);
}

// Called every frame
void Ashockwave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void Ashockwave::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	
}

void Ashockwave::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
}