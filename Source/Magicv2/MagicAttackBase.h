// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "MyCharacter.h"
#include "MagicAttackBase.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class MAGICV2_API AMagicAttackBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMagicAttackBase();

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="Coillions")
	USphereComponent* Coillions;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="Coillions")
	USceneComponent*NewCoillions;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void AOnComponentHit(UPrimitiveComponent*HitComponent,AActor* OtherActor,UPrimitiveComponent*OtherComp,FVector NormalImpulse,const FHitResult& Hit);

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Damage")
	int32 Damage = 10;

	UPROPERTY(EditDefaultsOnly,Category = "player")
	AMyCharacter* Player;

	UFUNCTION(BlueprintCallable)
	int32  GetDamage(){return Damage;};



};

