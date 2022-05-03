// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AiCharacter.h"
#include "AIController.h"


#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class MAGICV2_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	AMyAIController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
public:

UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="AttckOBJ")
	TSubclassOf<class ADefendpoint> AttackObj;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Enmey")
	TSubclassOf<class AAiCharacter> Enemys;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="enemy")
	class AAiCharacter* Enemy;

	
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Ai")
	float AISightRadius =500;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Ai")
	float AISightAge = 5.0;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Ai")
	float AILoseSightRadius = AISightRadius +50;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Ai")
	float AIFieldOfView = 90;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Ai")
	class UAISenseConfig_Sight* SightConfig;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "Ai")
	bool BIsPlayerDetected = false;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "Ai")
	float DistanceToPlayer = 0.0f;
};




