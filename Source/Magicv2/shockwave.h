// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "AiCharacter.h"

#include "shockwave.generated.h"
class USphereComponent;
class UProjectileMovementComponent;
UCLASS()
class MAGICV2_API Ashockwave : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ashockwave();

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="scene")
	USceneComponent* SceneComponent;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Timer")
	FTimerHandle  FTimerHandlerAttack;;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Array")
	TArray<AAiCharacter*> EnemysArray;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Coillions")
	USphereComponent* NewCoillions;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Coillions")
	USphereComponent* Coillions;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="ATTACK")
	bool HasAttack;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="ATTACK")
	bool EnemyInRange;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
	void ShockDestory();
	UFUNCTION()
	void ShockDestoryMesh();
	UFUNCTION(BlueprintImplementableEvent)
	void LaunchEnemy();
};





