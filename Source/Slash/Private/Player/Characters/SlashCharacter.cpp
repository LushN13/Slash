// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Characters/SlashCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// 在ASlashCharacter构造函数中添加CameraBoom的创建和初始化
ASlashCharacter::ASlashCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    
    //禁止角色跟随控制器旋转
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false; 
    bUseControllerRotationRoll = false;
 
    //创建弹簧臂 CameraBoom
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(GetRootComponent()); // 绑在根组件上
    CameraBoom->TargetArmLength = 300.f; // 默认臂长
   
    //弹簧臂使用控制器的旋转
    CameraBoom->bUsePawnControlRotation = true;

    //配置角色移动组件,让角色朝向移动方向
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
   
    //创建摄像机 ViewCamera
    ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
    ViewCamera->SetupAttachment(CameraBoom); //绑在弹簧臂末端
    
    //摄像机不随控制器旋转，跟着弹簧臂
    ViewCamera->bUsePawnControlRotation = false;
   
  
    
 

}

