// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mywalls.generated.h"

UCLASS()
class MAGICV2_API AMywalls : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMywalls();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Walls")
	UStaticMeshComponent* Walls;

	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
