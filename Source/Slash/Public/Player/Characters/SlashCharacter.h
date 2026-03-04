// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/Characters/SlashCharacterBase.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;



UCLASS()
class SLASH_API ASlashCharacter : public ASlashCharacterBase
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	//提供给其他类访问的接口
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetViewCamera() const { return ViewCamera; }
protected:


private:
	// 弹簧臂组件
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;
	//摄像机组件
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> ViewCamera;
	
};
