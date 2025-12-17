// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageModule.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class CORSO_UNREAL_2_API UDamageModule : public UObject
{
	GENERATED_BODY()
	
public:
	
	// Danno base (prima dei moltiplicatori)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage Module")
	float DamageBase = 10.f;

	// Moltiplicatore del danno (es. 1.0 = invariato, 2.0 = doppio)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage Module")
	float DamageMultiplier = 1.f;
	
	// Ritorna il danno singolo calcolato da questo modulo
	UFUNCTION(BlueprintCallable, Category="Damage Module")
	virtual float GetSingleDamage() const
	{
		return DamageBase * DamageMultiplier;
	}
	
};
