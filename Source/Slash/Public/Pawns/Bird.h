// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Bird.generated.h"



class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;



UCLASS()
class SLASH_API ABird : public APawn
{
	GENERATED_BODY()

public:	
	ABird();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	


protected:
	virtual void BeginPlay() override;
	
	// 回调函数：处理具体的移动和视角逻辑
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

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

	// 1. 映射上下文 (IMC)
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* SlashContext;

	// 2. 输入动作 (IA)
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	


};
