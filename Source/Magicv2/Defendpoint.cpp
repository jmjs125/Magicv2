// Fill out your copyright notice in the Description page of Project Settings.


#include "Defendpoint.h"

#include "AiCharacter.h"

// Sets default values
ADefendpoint::ADefendpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Altar =CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Altar"));
	newbox=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision2"));
	
	Altar->SetupAttachment(Root);
	
}

// Called when the game starts or when spawned
void ADefendpoint::BeginPlay()
{
	Super::BeginPlay();
	newbox->OnComponentBeginOverlap.AddDynamic(this, &ADefendpoint::OnOverlapBegin);
	newbox->OnComponentEndOverlap.AddDynamic(this, &ADefendpoint::OnOverlapEnd);
	Health= MaxHealth;
	Shield= MaxShield;
	
	
}

// Called every frame
void ADefendpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(Shield >= 0)
	{
		ShieldOn = true;
	}else
	{
		ShieldOn = false;
	}
	
}

void ADefendpoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		
		AAiCharacter* Enemy = Cast<AAiCharacter>(OtherActor);
		if(Enemy)
		{
			EnemysArray.Add(Enemy);
			if(EnemysArray.Num() > 0)
			{
				GetWorldTimerManager().ClearTimer(RegenTimerHandle);
				GetWorldTimerManager().SetTimer(AttackTimerHandle,this,&ADefendpoint::Damage, 1,true);
			}
			
		}

	
		
	}
	
	
}

void ADefendpoint::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	AAiCharacter* Enemy = Cast<AAiCharacter>(OtherActor);
	if(Enemy)
	{
		
		EnemysArray.Remove(Enemy);
		if(EnemysArray.Num() == 0)
		{
			GetWorldTimerManager().ClearTimer(AttackTimerHandle);
            SetTimer();
		}
		
	}
}

void ADefendpoint::Damage()
{
	
    			if(ShieldOn == true)
    			{
    				Shield = Shield -100;
    			}else
    			{
    				
    				Health = Health-100;
    				if(Health<= 0)
    				{
    					this->Destroy();
    				}
    			}
}

void ADefendpoint::Regen()
{
	
	
	 if(Health <= MaxHealth && Shield <=0)
	 {
	 	
	 	Health = Health+50;
	 }else
	 {
	 	Health = MaxHealth;
	 	
	 }
		 
	 if(Shield <= MaxShield&& Health == MaxHealth)
     		 {
     		 	Shield = Shield +50;
     		 	ShieldOn =true;
	 	
     		 }

	if(Health == MaxHealth&& Shield == MaxShield)
	{
		
		GetWorldTimerManager().ClearTimer(RegenTimerHandle);
	}
	
}

void ADefendpoint::SetTimer()
{
		GetWorldTimerManager().SetTimer(RegenTimerHandle,this,&ADefendpoint::Regen, 1,true);
}

