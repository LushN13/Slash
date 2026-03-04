// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SlashPlayerController.h"
#include "EnhancedInputSubsystems.h" // 添加此头文件以定义 UEnhancedInputLocalPlayerSubsystem
#include "EnhancedInputComponent.h"


ASlashPlayerController::ASlashPlayerController()
{
	//服务器向客户端同步数据
	bReplicates = true;
}

void ASlashPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//断言检测指针是否存在，不存在则崩溃；安全性检查
	check(SlashContext);

	//本地玩家增强输入子系统
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	//添加输入情景
	Subsystem->AddMappingContext(SlashContext, 0);

}

void ASlashPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//将输入组件强制转换为增强输入组件并使用了了断点检测
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASlashPlayerController::Move);
}


void ASlashPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	
	//得到Y轴的旋转
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);

	const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControllerPawn = GetPawn())
	{
		ControllerPawn->AddMovementInput(ForwardDir, InputAxisVector.Y);
		ControllerPawn->AddMovementInput(RightDir, InputAxisVector.X);
	}
}





