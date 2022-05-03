// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AiCharacter.h"
#include "ArrayManger.generated.h"

UCLASS()
class MAGICV2_API AArrayManger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrayManger();
	
	std::vector<AAiCharacter*> Enemies;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
