// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/SpawnableSphere.h"

// Sets default values
ASpawnableSphere::ASpawnableSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	//SphereCollision->SetEnableGravity(true);
	

}

// Called when the game starts or when spawned
void ASpawnableSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnableSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnableSphere::BP_Activate_Implementation(FObjecPoolActivationData ObjectPoolActivationData)
{
	IPoolable::BP_Activate_Implementation(ObjectPoolActivationData);
}

void ASpawnableSphere::BP_Deactivate_Implementation(FObjectPoolDeactivationData ObjectPoolDeactivationData)
{
	IPoolable::BP_Deactivate_Implementation(ObjectPoolDeactivationData);
}

