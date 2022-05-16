// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "MagicAttackBase.h"
#include "shockwave.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PlayerCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	PlayerCameraComponent->SetupAttachment(CastChecked<USceneComponent,UCapsuleComponent>(GetCapsuleComponent()));

	PlayerCameraComponent->SetRelativeLocation(FVector(0.0f ,0.0f, 50.0f +BaseEyeHeight));
	PlayerCameraComponent->bUsePawnControlRotation = true;

	NewCollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("NewBox"));

	GroundAttackSpawner =CreateDefaultSubobject<UBoxComponent>(TEXT("GroundSpawner"));
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxComponent->SetupAttachment(PlayerCameraComponent); 
	BoxComponent->TransformUpdated;

	GroundAttackSpawner->SetupAttachment(PlayerCameraComponent);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	Shield = Maxshield;


}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

if(Shield >=0)
{
	PlayerShield =true;
}else
{
	PlayerShield =false;
}
	
	
	if(Health <=0)
	{
		CreateWidget();
		//UGameplayStatics::OpenLevel(this,"MainMenu");
	}

	if(Health >= MaxHealth)
	{
		Health = MaxHealth;
	}
	if(Shield >=Maxshield)
	{
		Shield= Maxshield;
	}

	
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveLeft",this ,&AMyCharacter::MoveLeft);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AMyCharacter::JumpStart);
	PlayerInputComponent->BindAction("Jump",IE_Released,this,&AMyCharacter::StopJump);
	PlayerInputComponent->BindAction("Fire",IE_Pressed,this,&AMyCharacter::Shoot);
	PlayerInputComponent->BindAction("GroundAttack",IE_Pressed,this,&AMyCharacter::GroundAttack);
	//PlayerInputComponent->BindAction("GroundAttack",IE_Released,this,&AMyCharacter::StopGroundAttack);

	
	
}

void AMyCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction,Value*2000);
}

void AMyCharacter::MoveLeft(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction,Value);
}

void AMyCharacter::JumpStart()
{

	bPressedJump = true;
}

void AMyCharacter::StopJump()
{
	bPressedJump = false;
}

void AMyCharacter::Shoot()
{
	UWorld* const World = GetWorld();

	FRotator BoxRot = BoxComponent->GetComponentRotation();
	FVector BoxLocation = BoxComponent->GetComponentLocation();
	
	
	FireBall = World->SpawnActor<AMagicAttackBase>(ProjectileClass, BoxLocation, BoxRot);
	if (FireBall) FireBall->Damage += DamageBuff;
	else
	{
		FHitResult hitRes;
		FVector Start = GetActorLocation();

		Start.Z += 50.f;
		Start.X += 200.f;

		FVector ForwardVector = GetActorForwardVector();
		FVector End = ((ForwardVector * 50000.f) + Start);
		FCollisionQueryParams CollisionParams;
		ActorLineTraceSingle(hitRes, Start, End, ECC_WorldStatic, CollisionParams);
		if (hitRes.GetActor())
		{
			AAiCharacter* enemy = Cast<AAiCharacter>(hitRes.GetActor());
			if (enemy) enemy->Health -= DamageBuff;
		}
	}
	
	
	
}



void AMyCharacter::HealthShop()
{
	if(Money >= Shop.HealthPrice)
	{
		
		Money = Money - Shop.HealthPrice;
		MaxHealth = MaxHealth + FMath::RandRange(25,50);
		Shop.HealthPrice = Shop.HealthPrice + FMath::RandRange(25,50);
		Health = MaxHealth;
	}
	
		
	
}

void AMyCharacter::DamageShop()
{
	if(Money >= Shop.DamagePrice)
	{
		Money = Money - Shop.DamagePrice;
		DamageBuff = DamageBuff + FMath::RandRange(10,25);
		Shop.DamagePrice = Shop.DamagePrice + FMath::RandRange(25,50);
		
	}
}

void AMyCharacter::ShieldShop()
{
	if(Money >= Shop.ShieldPrice)
	{
		Money = Money - Shop.ShieldPrice;
		Maxshield = Maxshield + FMath::RandRange(25,50);
		Shop.ShieldPrice = Shop.ShieldPrice + FMath::RandRange(25,50);
		Shield = Maxshield;
	}
}

void AMyCharacter::PushShop()
{
	if(Money >= Shop.Pushprice)
	{
		if(Shop.HasBroughPush == false)
		{
			Money = Money- Shop.Pushprice;
			Shop.HasBroughPush =true;
		}
		
	}
}

void AMyCharacter::GroundAttack()
{
	UWorld* const World = GetWorld();
	FRotator BoxRot = GroundAttackSpawner->GetComponentRotation();
	FVector BoxLocation = GroundAttackSpawner->GetComponentLocation();
	
	if(Shop.HasBroughPush == true)
	{
		if(GroundAttackCalled == false)
		{
			
			GroundAttackCalled=true;
			ShockWave = World->SpawnActor<Ashockwave>(TSubShockWave,BoxLocation,BoxRot);
			ShockWave->HasAttack = true;
			
			GetWorldTimerManager().SetTimer(ResetGroundAttack,this,&AMyCharacter::StopGroundAttack, 5
			);
     
			
		}
	
	}

	
}

void AMyCharacter::StopGroundAttack()
{
	
 GroundAttackCalled =false;
}

void AMyCharacter::RegenFunction()
{
	if(Shield <= Maxshield )
  		{
  			Shield = Shield +10;
  		}
	if( Shield >= Maxshield)
	{
		
		Shield = Maxshield;
		GetWorldTimerManager().ClearTimer(RegenTimer);
	}
	
}

void AMyCharacter::SetTimer()
{
	GetWorldTimerManager().SetTimer(RegenTimer,this,&AMyCharacter::RegenFunction,1,true);
}






