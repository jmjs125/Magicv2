// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class MAGICV2_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();
	UPROPERTY(VisibleAnywhere,Category="Staticmesh")
	UStaticMeshComponent* Door;
	UPROPERTY(VisibleAnywhere,Category="Staticmesh")
	UStaticMeshComponent* DoorFrame;
	UPROPERTY(VisibleAnywhere,Category="Root")
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere,Category="Box")
	UBoxComponent*NewBox;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Setting")
	int32 Price;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="Setting")
	bool CanOpen;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category =" Setting")
	TSubclassOf<class ACharacter> Player;
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void DoorOpen();

	UFUNCTION(BlueprintCallable)
	void SetDoor();

	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	

};
