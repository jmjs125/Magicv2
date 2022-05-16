// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ABaseItem.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Particles/ParticleEmitter.h"
#include "AiCharacter.generated.h"

UCLASS()
class MAGICV2_API AAiCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAiCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category = "box")
	UBoxComponent* Box;
UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Box")
	UBoxComponent* Newbox;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Box")
	USkeletalMeshComponent* SkeletalMeshComponent;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category = "health")
	float Health = 100;
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category = "health")
	float MaxHealth = 100;

	UPROPERTY(EditDefaultsOnly,Category = "baseItem")
	TSubclassOf<AABaseItem> BaseItem;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="Attack")
	bool CanAttack;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Attack")
	int32 Damage;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AttackPoint")
	class ADefendpoint* AttackPoint;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="Hit")
	bool EnemyBeenHit;

	UPROPERTY(EditAnywhere,Category="force")
	float Force = 50;
		
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	
};




