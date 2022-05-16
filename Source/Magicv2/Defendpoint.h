// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MyAIController.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Defendpoint.generated.h"

UCLASS()
class MAGICV2_API ADefendpoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADefendpoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Root")
	USceneComponent*Root;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Boxcolision")
	UBoxComponent* newbox;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="STAICMESHAltar")
	UStaticMeshComponent* Altar;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Array")
	TArray<AAiCharacter*> EnemysArray;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="TimeHandler")
	FTimerHandle AttackTimerHandle;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="TimeHandler")
	FTimerHandle RegenTimerHandle;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Setting")
	float MaxHealth = 1500;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Setting")
	float MaxShield = 1500;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Setting")
	float Health;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Setting")
	float Shield;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Setting")
	bool ShieldOn;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Setting")
	bool CanAttackDefendPoint;
	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void Damage();
	UFUNCTION()
	void Regen();
	UFUNCTION()
	void SetTimer();
	
	UFUNCTION(BlueprintImplementableEvent)
	void CreateWidget();
	

};
