// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <bit>

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Poolable.generated.h"

// Expand this with any needed type of data for pooling objects (Activation)
USTRUCT(BlueprintType)
struct FObjecPoolActivationData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, category = "ObjectPoolStruct")
	FTransform ObjectPoolTransform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, category = "ObjectPoolStruct")
	FName ObjectPoolName;
};

USTRUCT(BlueprintType)
struct FObjectPoolDeactivationData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, category = "ObjectPoolStruct")
	FTransform ObjectPoolTransform;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable, BlueprintType)
class UPoolable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CORSO_UNREAL_2_API IPoolable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// FUNCTIONS TO CALL IN C++ IF THE INTERFACE IS IMPLEMENTED IN THE CLASS
	// General version to call in C++
	void Active(FObjecPoolActivationData ObjectPoolActivationData) { NativeActivate(ObjectPoolActivationData); }
	void Deactive(FObjectPoolDeactivationData ObjectPoolDeactivationData) { NativeDeactivate(ObjectPoolDeactivationData); }

	// FUNCTIONS TO BE OVERRIDDEN IN BLUEPRINTS

	// To be implemented in Blueprint
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Object Pooling")
	void BP_Activate(FObjecPoolActivationData ObjectPoolActivationData);

	// Native version to call in C++
	virtual void NativeActivate(FObjecPoolActivationData ObjectPoolActivationData)
	{
		BP_Activate(ObjectPoolActivationData);
	}

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Object Pooling")
	void BP_Deactivate(FObjectPoolDeactivationData ObjectPoolDeactivationData);

	virtual void NativeDeactivate(FObjectPoolDeactivationData ObjectPoolDeactivationData) { BP_Deactivate(ObjectPoolDeactivationData); }
};
