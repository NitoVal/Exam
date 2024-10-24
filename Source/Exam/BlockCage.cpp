// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockCage.h"

#include "FireTorch.h"

// Sets default values
ABlockCage::ABlockCage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	BlockMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMeshComponent"));
	BlockMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABlockCage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockCage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ActivatedTorch = 0;
	for (AFireTorch* Torch : Torches)
	{
		if (Torch->bIsActive)
			ActivatedTorch++;
		if (ActivatedTorch == Torches.Max())
		{
			AddActorLocalOffset(FVector(0,0,.5f));
		}
	}
}

