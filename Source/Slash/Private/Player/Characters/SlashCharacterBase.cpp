// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Characters/SlashCharacterBase.h"


ASlashCharacterBase::ASlashCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");//Fname不需要使用TEXT宏
	//创建一个附着在Mesh上的武器插槽
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	//设置武器不存在碰撞
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


void ASlashCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



