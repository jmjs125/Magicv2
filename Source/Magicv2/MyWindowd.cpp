// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWindowd.h"

// Sets default values
AMyWindowd::AMyWindowd()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WallsWindows = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Walls"));

}

// Called when the game starts or when spawned
void AMyWindowd::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyWindowd::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

