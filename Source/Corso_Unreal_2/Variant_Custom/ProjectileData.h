// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ProjectileData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CORSO_UNREAL_2_API UProjectileDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintType, Category = "Spawner Data")
	TSoftObjectPtr<UStaticMesh> SpawnerMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintType, Category = "Spawner Data")
	FName SpawnerName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintType, Category = "Spawner Data")
	TSubclassOf<AActor> ProjectileBaseClass;
	
public:
	
	UFUNCTION(BlueprintCallable, Category = "Spawner")
	TSoftObjectPtr<UStaticMesh> GetSpawnerMesh() const { return SpawnerMesh; }
	
	UFUNCTION(BlueprintCallable, Category = "Spawner")
	FName GetSpawnerName() const { return SpawnerName; }
	
	UFUNCTION(BlueprintCallable, Category = "Spawner")
	TSubclassOf<AActor> GetProjectileBaseClass() const { return ProjectileBaseClass; }	
	
	
};
