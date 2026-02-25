// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bird.generated.h"


class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;



UCLASS()
class SLASH_API ABird : public APawn
{
	GENERATED_BODY()

private:
	//碰撞胶囊体
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;
	
	//鸟的骨骼网格体
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* BirdMesh;

	//玩家弹簧臂
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* PlayerSpringArm;

	//玩家摄像机
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* PlayerCamera;


public:	
	ABird();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

	


};
