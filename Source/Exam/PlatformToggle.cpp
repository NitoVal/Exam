// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformToggle.h"

#include "ExamCharacter.h"

// Sets default values
APlatformToggle::APlatformToggle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	ToggleMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ToggleMeshComponent"));
	ToggleMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlatformToggle::BeginPlay()
{
	Super::BeginPlay();
	bIsActive = false;
	ToggleMeshComponent->SetMaterial(0,OffMaterial);
	PlaformB->SetActorHiddenInGame(!bIsActive);
	PlaformB->SetActorEnableCollision(false);
}

// Called every frame
void APlatformToggle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformToggle::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other->IsA(AExamCharacter::StaticClass()))
	{
		bIsActive = !bIsActive;
		ToggleMeshComponent->SetMaterial(0,bIsActive ? OnMaterial : OffMaterial);
		
		PlaformA->SetActorHiddenInGame(bIsActive);
		PlaformA->SetActorEnableCollision(!bIsActive);
		
		PlaformB->SetActorHiddenInGame(!bIsActive);
		PlaformB->SetActorEnableCollision(bIsActive);
	}
}


