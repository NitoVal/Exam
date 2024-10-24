// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockCage.generated.h"

class AFireTorch;

UCLASS()
class EXAM_API ABlockCage : public AActor
{
	GENERATED_BODY()
	
public:	
	ABlockCage();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* DefaultSceneRoot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* BlockMeshComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Block")
	TArray<AFireTorch*> Torches;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	int ActivatedTorch;
};
