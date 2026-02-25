


#include "Item/Item.h"
#include "slash/DebugMacros.h"
#include "Slash/Slash.h"
AItem::AItem()
	:Amplitude(0.25f), TimeConstant(5.f),
	ItemMesh(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent")))
{
 	
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = ItemMesh;
	//CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));

}


void AItem::BeginPlay()
{
	Super::BeginPlay();
	

}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}


void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	RunningTime += DeltaTime;
	
}

