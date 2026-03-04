// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SlashCharacterBase.generated.h"

UCLASS()
class SLASH_API ASlashCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ASlashCharacterBase();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "战斗")
	TObjectPtr<USkeletalMeshComponent> Weapon;


};
