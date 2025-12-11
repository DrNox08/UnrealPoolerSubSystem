// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Poolable.h"
#include "ObjectPoolSubSystem.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FObjectPool
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, category = "ObjectPoolStruct")
	TArray<TScriptInterface<IPoolable>> UsablePooLingObjects;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, category = "ObjectPoolStruct")
	TArray<TScriptInterface<IPoolable>> ActivePoolingObjects;
};

USTRUCT(BlueprintType)
struct FPoolClassStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Pool Stats")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(BlueprintReadOnly, Category = "Pool Stats")
	int32 UsableCount = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Pool Stats")
	int32 ActiveCount = 0;
};


UCLASS()
class CORSO_UNREAL_2_API UObjectPoolSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	//Map with the Objects we want to pool
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Object Pool SubSystem")
	TMap<TSubclassOf<AActor>, FObjectPool> ObjectPoolMap;

	//Add an object to the pool
	UFUNCTION(BlueprintCallable, Category = "Object Pool SubSystem")
	void AddPool(TSubclassOf<AActor> ClassToPool, int32 InitialSize = 10);

	UFUNCTION(BlueprintCallable, Category = "Object Pool SubSystem")
	TScriptInterface<IPoolable> GetObjectFromPool(TSubclassOf<AActor> ClassToPool);

	UFUNCTION(BlueprintCallable, Category = "Object Pool SubSystem")
	void ReturnObjectToPool(TSubclassOf<AActor> ClassToPool, TScriptInterface<IPoolable> ActorToReturn);

	UFUNCTION(BlueprintCallable, Category = "Object Pool SubSystem")
	TArray<FPoolClassStats> GetPoolStats() const;
};
