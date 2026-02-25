// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SlashPlayerController.h"
#include "EnhancedInputSubsystems.h" // 添加此头文件以定义 UEnhancedInputLocalPlayerSubsystem
#include "EnhancedInputComponent.h"

ASlashPlayerController::ASlashPlayerController()
{
	bReplicates = true;
}


void ASlashPlayerController::Move(const FInputActionValue& InputActionValue)
{
}

void ASlashPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(SlashContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(SlashContext, 0);

}

void ASlashPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
}
