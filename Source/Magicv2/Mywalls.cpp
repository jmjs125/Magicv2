// Fill out your copyright notice in the Description page of Project Settings.


#include "Mywalls.h"

#include "NavigationSystemTypes.h"

// Sets default values
AMywalls::AMywalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	Walls = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Walls"));
	

	
}

// Called when the game starts or when spawned
void AMywalls::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMywalls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

