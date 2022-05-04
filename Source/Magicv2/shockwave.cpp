// Fill out your copyright notice in the Description page of Project Settings.

#include "AiCharacter.h"
#include "shockwave.h"
#include "Particles/ParticleSystem.h"

// Sets default values
Ashockwave::Ashockwave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scenecomp"));


	Coillions = CreateDefaultSubobject<USphereComponent>(TEXT("NewCollsion"));
	Coillions->SetGenerateOverlapEvents(true);
	Coillions->BodyInstance.SetCollisionProfileName("Projectile");

	
}

// Called when the game starts or when spawned
void Ashockwave::BeginPlay()
{
	Super::BeginPlay();
	Coillions->OnComponentBeginOverlap.AddDynamic(this, &Ashockwave::OnOverlapBegin);
	Coillions->OnComponentEndOverlap.AddDynamic(this, &Ashockwave::OnOverlapEnd);
}

// Called every frame
void Ashockwave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(HasAttack == true)
	{
		
		ShockDestory();
	}
	if(EnemyInRange ==true)
	{
		LaunchEnemy();
	}
}


void Ashockwave::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if(OtherActor)
	{
		AAiCharacter* Enemy = Cast<AAiCharacter>(OtherActor);
		if(Enemy)
		{
			EnemyInRange =true;
			EnemysArray.Add(Enemy);
			if(EnemysArray.Num() > 0)
			{
				UE_LOG(LogTemp,Warning,TEXT("added "))
				
			}
			
		}
	}
	
}

void Ashockwave::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	AAiCharacter* Enemy = Cast<AAiCharacter>(OtherActor);
	if(Enemy)
	{
		
		EnemysArray.Remove(Enemy);
		if(EnemysArray.Num() == 0)
		{
			UE_LOG(LogTemp,Warning,TEXT("removed"))
			EnemyInRange= false;
		}
		
	}
}
void Ashockwave::ShockDestory()
{
	
	
	GetWorldTimerManager().SetTimer(FTimerHandlerAttack,this,&Ashockwave::ShockDestoryMesh, 5,true);


	
}

void Ashockwave::ShockDestoryMesh()
{
	this->Destroy();
	
	HasAttack = false;
	GetWorldTimerManager().ClearTimer(FTimerHandlerAttack);
	
	
}
