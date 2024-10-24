// Fill out your copyright notice in the Description page of Project Settings.


#include "WheelMachine.h"

#include "ExamCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
AWheelMachine::AWheelMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	MachineMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineMeshComponent"));
	MachineMeshComponent->SetupAttachment(RootComponent);

	WheelMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WheelMeshComponent"));
	WheelMeshComponent->SetupAttachment(RootComponent);

	BlackButtonComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BlackButtonComponent"));
	BlackButtonComponent->SetupAttachment(RootComponent);
	BlackButtonComponent->OnComponentHit.AddDynamic(this, &AWheelMachine::OnBlackButtonHit);
	
	YellowButtonComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("YellowButtonComponent"));
	YellowButtonComponent->SetupAttachment(RootComponent);
	YellowButtonComponent->OnComponentHit.AddDynamic(this, &AWheelMachine::OnYellowButtonHit);

	PointerMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PointerMeshComponent"));
	PointerMeshComponent->SetupAttachment(RootComponent);
	
	RotationSpeed = 100.0f;
	bIsSpinning = false;
}

void AWheelMachine::BeginPlay()
{
	Super::BeginPlay();
	
}
void AWheelMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsSpinning)
		WheelMeshComponent->AddLocalRotation(FRotator(0,10,0));
}

void AWheelMachine::OnBlackButtonHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!bIsSpinning)
	{
		bIsSpinning = true;
		GetWorldTimerManager().SetTimer(StopTimerHandle, this, &AWheelMachine::StopWheel, 1.f, false);
	}
}

void AWheelMachine::OnYellowButtonHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!bIsSpinning)
	{
		bIsSpinning = true;
		GetWorldTimerManager().SetTimer(StopTimerHandle, this, &AWheelMachine::StopWheel, 1.f, false);
	}
}


int AWheelMachine::SpinWheel()
{
	int RandomInt = FMath::RandRange(0, 3);
	float LiteralFloat = 90.f;
	float Result = RandomInt * LiteralFloat;
	FRotator NewRotation = FRotator(0, Result, 90.f);
	WheelMeshComponent->SetRelativeRotation(NewRotation);
	
	return RandomInt;
}
void AWheelMachine::StopWheel()
{
	bIsSpinning = false;
	int result = SpinWheel();
}

void AWheelMachine::CheckResult()
{
	
}
