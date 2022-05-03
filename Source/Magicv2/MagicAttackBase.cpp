// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicAttackBase.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "AiCharacter.h"
#include "MyCharacter.h"

// Sets default values
AMagicAttackBase::AMagicAttackBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Coillions  = CreateDefaultSubobject<USphereComponent>(TEXT("Collison"));
	Coillions->SetGenerateOverlapEvents(true);
	Coillions->BodyInstance.SetCollisionProfileName("Projectile");
	RootComponent =Coillions;

	NewCoillions = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	NewCoillions->SetupAttachment(Coillions);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = Coillions;
	ProjectileMovement->InitialSpeed = 30000.f;
	ProjectileMovement->MaxSpeed = 30000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	
	
}

// Called when the game starts or when spawned
void AMagicAttackBase::BeginPlay()
{
	Super::BeginPlay();
	
	Coillions->OnComponentBeginOverlap.AddDynamic(this, &AMagicAttackBase::OnOverlapBegin);
	Coillions->OnComponentEndOverlap.AddDynamic(this, &AMagicAttackBase::OnOverlapEnd);

	Coillions->OnComponentHit.AddDynamic(this,&AMagicAttackBase::AOnComponentHit);

	
}

// Called every frame
void AMagicAttackBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMagicAttackBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		AAiCharacter* Enemy = Cast<AAiCharacter>(OtherActor);
	
		if(Enemy)
		{
			this->Destroy();
			Enemy->Health -= Damage;
			Enemy->EnemyBeenHit = true;
		}
	
			
	}
}

void AMagicAttackBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AMagicAttackBase::AOnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));
	}
}











