// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AiCharacter.h"

#include "GameFramework/GameModeBase.h"
#include "Magicv2GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MAGICV2_API AMagicv2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	AMagicv2GameModeBase();

public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = "Array")
	TArray<class AAiCharacter*> EnemyArray;

	UFUNCTION()
	void AddArray();
	void BeginPlay();
	
	



};
