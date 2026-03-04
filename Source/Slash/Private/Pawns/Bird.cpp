// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
ABird::ABird()
	//胶囊体初始化
	:Capsule(CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"))),
	//鸟网格初始化
	BirdMesh(CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"))),
	//玩家摄像机初始化
	PlayerCamera(CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"))),
	//玩家弹簧臂初始化
	PlayerSpringArm(CreateDefaultSubobject<USpringArmComponent>(TEXT("PlayerSpringArm")))
{
	PrimaryActorTick.bCanEverTick = true;
	SetRootComponent(Capsule);
	Capsule->SetCapsuleHalfHeight(110.042976);
	Capsule->SetCapsuleRadius(56.951077);

	BirdMesh->SetupAttachment(GetRootComponent());

	PlayerSpringArm->SetupAttachment(GetRootComponent());
	PlayerCamera->SetupAttachment(PlayerSpringArm);
	bUseControllerRotationYaw = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}


void ABird::BeginPlay()
{
	Super::BeginPlay();

	// 获取 PlayerController
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		// 获取 EnhancedInputLocalPlayerSubsystem
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// 添加映射上下文，优先级设为 0
			Subsystem->AddMappingContext(SlashContext, 0);
		}
	}
	
}



void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	

	// 强制转换为增强输入组件
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// 绑定移动 (Triggered 表示按下期间每帧触发)
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ABird::Move);

		// 绑定视角
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABird::Look);
	}
}

void ABird::Move(const FInputActionValue& Value)
{
	// 1. 获取输入的二维向量 (X=左/右, Y=前/后)
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// 2. 获取控制器的旋转（摄像机朝向）
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f); // 只保留水平方向的旋转

		// 3. 计算前方和右方
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// 4. 应用移动
		AddMovementInput(ForwardDirection, MovementVector.Y); // 前后
		AddMovementInput(RightDirection, MovementVector.X);   // 左右
	}
}

void ABird::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// 添加鼠标/手柄输入到控制器的 Pitch (上下) 和 Yaw (左右)
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}