// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Invetory.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"


#include "MyCharacter.generated.h"

UCLASS()
class MAGICV2_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION()
    void MoveForward(float Value);

	UFUNCTION()
    void MoveLeft(float Value);

	UFUNCTION()
    void JumpStart();

	UFUNCTION()
    void StopJump();
   
    UFUNCTION()
   void Shoot();

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void PlayersDead();
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="camera")
	UCameraComponent* PlayerCameraComponent;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category = "Money")
	int32 Money;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="Damage")
	int32 Damage=10;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="life")
	float Health;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="life")
	float MaxHealth=100;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="life")
	float Shield;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="life")
	float Maxshield =100;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="life")
	bool PlayerShield = true;
	
	UPROPERTY(EditDefaultsOnly,Category = "PROJECTION")
	TSubclassOf<class AMagicAttackBase> ProjectileClass;

	UPROPERTY(EditAnywhere,Category ="GroundAttack")
	TSubclassOf<class Ashockwave> TSubShockWave;

	UFUNCTION(BlueprintCallable)
	int32  GetPlayerMoney(){return Money;};

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category="Box")
	UBoxComponent* BoxComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	class UBoxComponent* NewCollisionVolume;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	class UBoxComponent* GroundAttackSpawner;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="shop")
	FShop Shop;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="shop")
	class AMagicAttackBase* FireBall;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="GroundAttack")
	class Ashockwave* ShockWave;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="attack")
	bool GroundAttackCalled;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category ="Timer")
	FTimerHandle ResetGroundAttack;

	UFUNCTION(BlueprintCallable)
	void HealthShop();

	UFUNCTION(BlueprintCallable)
	void DamageShop();
	
	UFUNCTION(BlueprintCallable)
	void ShieldShop();

	UFUNCTION(BlueprintCallable)
	void PushShop();

	UFUNCTION(BlueprintCallable)
	void GroundAttack();
	UFUNCTION(BlueprintCallable)
	void StopGroundAttack();
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="playerbeenhit");
	bool BeenHit;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category ="Timer")
	FTimerHandle RegenTimer;
	UFUNCTION(BlueprintCallable)
	void RegenFunction();
	UFUNCTION(BlueprintCallable)
		void SetTimer();

	UPROPERTY()
	int32 DamageBuff=0;

	UFUNCTION(BlueprintImplementableEvent)
	void CreateWidget();
	
};
