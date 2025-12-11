// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/ObjectPoolSubSystem.h"
#include "Engine/World.h"

void UObjectPoolSubSystem::AddPool(TSubclassOf<AActor> ClassToPool, int32 InitialSize)
{
	if (!GetWorld()) return;

	if (!IsValid(ClassToPool)) return;

	if (ClassToPool->ImplementsInterface(UPoolable::StaticClass()) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Trying to pool a class that does not implement the Poolable interface"));
		return;
	}

	FObjectPool ObjectPoolToCreate;

	FActorSpawnParameters SpawnParams;

	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	for (int i = 0; i < InitialSize; i++)
	{
		AActor* ActorRef = GetWorld()->SpawnActor<AActor>(ClassToPool, SpawnParams);

		ObjectPoolToCreate.UsablePooLingObjects.AddUnique(ActorRef);
	}

	ObjectPoolMap.Add(ClassToPool, ObjectPoolToCreate);
}

TScriptInterface<IPoolable> UObjectPoolSubSystem::GetObjectFromPool(TSubclassOf<AActor> ClassToPool)
{
	if (!GetWorld()) return nullptr;

	if (!ObjectPoolMap.Contains(ClassToPool)) return nullptr;
	
	FObjectPool* PoolObject = ObjectPoolMap.Find(ClassToPool);

	TScriptInterface<IPoolable> ActorToReturn;

	// If there are no usable objects, spawn a new one
	if ( PoolObject->UsablePooLingObjects.IsEmpty())
	{
		FActorSpawnParameters SpawnParams;

		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		ActorToReturn = GetWorld()->SpawnActor<AActor>(ClassToPool, SpawnParams);

		PoolObject->ActivePoolingObjects.AddUnique(ActorToReturn);
	}
	else
	{
		// Get the first usable object
		ActorToReturn = PoolObject->UsablePooLingObjects[0];

		PoolObject->UsablePooLingObjects.Remove(ActorToReturn);
		
		PoolObject->ActivePoolingObjects.AddUnique(ActorToReturn);
	}

	return ActorToReturn;
}

void UObjectPoolSubSystem::ReturnObjectToPool(TSubclassOf<AActor> ClassToPool, TScriptInterface<IPoolable> ActorToReturn)
{
	if (!GetWorld()) return;

	if (!ObjectPoolMap.Contains(ClassToPool)) return;

	FObjectPool* PoolObject = ObjectPoolMap.Find(ClassToPool);

	if (!PoolObject->ActivePoolingObjects.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Trying to add to the pool an object that was not registered before"));
	}

	PoolObject->ActivePoolingObjects.Remove(ActorToReturn);

	PoolObject->UsablePooLingObjects.AddUnique(ActorToReturn);
}

TArray<FPoolClassStats> UObjectPoolSubSystem::GetPoolStats() const
{
	TArray<FPoolClassStats> StatsArray;

	for (const TPair<TSubclassOf<AActor>, FObjectPool>& Entry : ObjectPoolMap)
	{
		FPoolClassStats Stats;

		Stats.ActorClass = Entry.Key;
		Stats.UsableCount = Entry.Value.UsablePooLingObjects.Num();
		Stats.ActiveCount = Entry.Value.ActivePoolingObjects.Num();
		StatsArray.Add(Stats);
	}
	return StatsArray;
}



