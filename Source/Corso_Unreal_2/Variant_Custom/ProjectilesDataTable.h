// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Materials/MaterialInstance.h"
#include "ProjectilesDataTable.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FProjectileData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName ProjectileName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText LocalizedName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UMaterialInstance> ProjectileMaterial;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector Scale = FVector(1.0f, 1.0f, 1.0f);
	
};