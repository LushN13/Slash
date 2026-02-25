// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


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
	
}



void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

