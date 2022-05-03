// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "AiCharacter.h"
#include "AIController.h"



#include "Spawners.generated.h"

UCLASS()
class MAGICV2_API ASpawners : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawners();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	UBoxComponent*Box;

	UPROPERTY()
	float SpawnWave =5.0f;



	UPROPERTY(EditDefaultsOnly,Category = "Enemyclass")
	TSubclassOf<class AAiCharacter> EnemyClass;
	
	
	TSubclassOf<class ArrayManger> Array;



//timers
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="TimeHandler")
	FTimerHandle WaveStarting;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="TimeHandler")
	FTimerHandle WaveDelay;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="Spawner")
	float Timer = 5;

	// spawners varaiables 
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="Spawner")
	int32 Wave = 0;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="Spawner")
	int32 Spawned = 0;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="Spawner")
	int32 SpawnAmout = 2;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= "Spawner")
	bool CanSpawn =true;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,category ="Spawner")
	int32 DeadEnemies;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,category ="Spawner")
	int32 DeathTracker;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= "Spawner")
	bool WaveInProgress =true;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= "Spawner")
	bool Odd =true;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,category ="Spawner")
	TArray<AActor*> SpawnLocations; 

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="Spawner")
	int32 NewMaxHealth;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="Spawner")
	int32 NewDamage;
	
	UFUNCTION()
	void SpawnFunction();
	UFUNCTION()
	void StartWave();
	AController* GetOwnerController() const;
	UFUNCTION()
	void CountDead(AActor* DEAD);
	UFUNCTION()
	void NextWave();
	UFUNCTION()
	void TimerFunction();
	UFUNCTION()
	void SetTimer();

	


};


