// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Poolable.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "SpawnableSphere.generated.h"

UCLASS()
class CORSO_UNREAL_2_API ASpawnableSphere : public AActor, public IPoolable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnableSphere();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	USceneComponent* Root;

	// UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	// USphereComponent* SphereCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BP_Activate_Implementation(FObjecPoolActivationData ObjectPoolActivationData) override;

	virtual void BP_Deactivate_Implementation(FObjectPoolDeactivationData ObjectPoolDeactivationData) override;
};
