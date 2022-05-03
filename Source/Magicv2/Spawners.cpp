// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawners.h"
#include "Magicv2GameModeBase.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TimerManager.h"
#include "AiCharacter.h"
#include "ArrayManger.h"


// Sets default values
ASpawners::ASpawners()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Wave = 1;
	Timer = 10;
	WaveInProgress = true;
	NewMaxHealth = 100;
	NewDamage =10;
}

// Called when the game starts or when spawned
void ASpawners::BeginPlay()
{
	Super::BeginPlay();
	
	
	UE_LOG(LogTemp,Error,TEXT("beginplay"));
	SetTimer();



}

// Called every frame
void ASpawners::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	
}



void ASpawners::SpawnFunction()
{
	UWorld* const World = GetWorld();
 	const FRotator BoxRot = Box->GetComponentRotation();
 	const FVector BoxLocation = Box->GetComponentLocation();
 	WaveInProgress =true;
		if(Spawned < SpawnAmout)
		{
			UE_LOG(LogTemp,Error,TEXT("Spawned"));
				if(CanSpawn)
				
				{
					AAiCharacter* NewChar = World->SpawnActor<class AAiCharacter>(EnemyClass,SpawnLocations[FMath::RandRange(0,SpawnLocations.Num()-1)]->GetActorLocation(), BoxRot);
					NewChar->MaxHealth = NewMaxHealth;
					NewChar->Health = NewChar->MaxHealth;
					NewChar->Damage = NewDamage;
					Spawned = Spawned+1;
					NewChar->OnDestroyed.AddDynamic(this, &ASpawners::CountDead);
					
					
					
				}
			
			if(Spawned >= SpawnAmout)
			{
				
				CanSpawn = false;
			}
		}
}

void ASpawners::StartWave()
{
	
	GetWorldTimerManager().SetTimer(WaveDelay,this,&ASpawners::NextWave, 10,false);
	WaveInProgress = false;
	
	
	
	
}

AController* ASpawners::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr)
		return nullptr;
	return  OwnerPawn->GetController();
}
void ASpawners::CountDead(AActor* DEAD)
{
	DeadEnemies++;
	
	
		if(DeadEnemies == SpawnAmout)
        	{
        		
        		StartWave();
        	}
	
	
	
}

void ASpawners::NextWave()
{
	GetWorldTimerManager().ClearTimer(WaveDelay);
	//wave adds up
	Wave = Wave++;
	Timer = 10;
	NewMaxHealth= NewMaxHealth+ FMath::RandRange(25,50);
	NewDamage = NewDamage + FMath::RandRange(10,20);
	// incresse amout of many 
	SpawnAmout = SpawnAmout + Wave * FMath::RandRange(1,3);
	CanSpawn = true;
	DeadEnemies = 0;
	Spawned = 0;

	
	SpawnFunction();
	
	
	
}

void ASpawners::TimerFunction()
{
	
	StartWave();
	
}

void ASpawners::SetTimer()
{
	GetWorldTimerManager().SetTimer(WaveStarting,this,&ASpawners::SpawnFunction, 1,true);
}








	
