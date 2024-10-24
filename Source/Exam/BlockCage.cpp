// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockCage.h"

// Sets default values
ABlockCage::ABlockCage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

