// Fill out your copyright notice in the Description page of Project Settings.


#include "FireTorch.h"

#include "ExamCharacter.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
AFireTorch::AFireTorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	TorchMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TorchMeshComponent"));
	TorchMeshComponent->SetupAttachment(RootComponent);
	
	TorchVFX = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	TorchVFX->SetupAttachment(RootComponent);
	TorchVFX->SetAutoActivate(false);
}

// Called when the game starts or when spawned
void AFireTorch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFireTorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFireTorch::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other->IsA(AExamCharacter::StaticClass()) && !bIsActive)
	{
		bIsActive = true;
		TorchVFX->Activate();
	}
}

