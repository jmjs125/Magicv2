// Fill out your copyright notice in the Description page of Project Settings.

#include "Perception/AISenseConfig_Sight.h"
#include "MyAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "AiCharacter.h"
#include "Defendpoint.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	SightConfig =CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent")));
	
	SightConfig->SightRadius= AISightRadius;
	SightConfig->LoseSightRadius =AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);
        
	SightConfig->DetectionByAffiliation.bDetectEnemies =true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies =true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals =true;
	

	
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
}




void AMyAIController::Tick(float DeltaSeconds)
	{
		Super::Tick(DeltaSeconds);

		APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
		AActor* AttackObject = UGameplayStatics::GetActorOfClass(GetWorld(),AttackObj);
	
	
	if(LineOfSightTo(AttackObject))
	{
			SetFocus(AttackObject);
			MoveToActor(AttackObject,5);
	}
	
	
		
	}

	
	






