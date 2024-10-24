// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformToggle.generated.h"

UCLASS()
class EXAM_API APlatformToggle : public AActor
{
	GENERATED_BODY()
	
public:	
	APlatformToggle();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* DefaultSceneRoot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* ToggleMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Toggle | Material")
	UMaterial* OnMaterial;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Toggle | Material")
	UMaterial* OffMaterial;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Toggle | Platforms")
	AActor* PlaformA;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Toggle | Platforms")
	AActor* PlaformB;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
private:
	bool bIsActive;
	
};
