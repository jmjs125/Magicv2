// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "AiCharacter.h"
#include "Invetory.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FShop
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Shop")
	int32 DamagePrice = 50;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Shop")
	int32 HealthPrice = 25;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Shop")
	int32 ShieldPrice = 35;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Shop")
	int32 Pushprice = 50;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Shop")
	bool HealthCanBuy = false;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Shop")
	bool DamageCanBuy = false;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Shop")
	bool ShieldCanBuy = false;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category ="shop")
	bool HasBroughPush =false;
};

UCLASS()
class MAGICV2_API UInvetory : public UObject
{
	GENERATED_BODY()
	UInvetory();
	
};
