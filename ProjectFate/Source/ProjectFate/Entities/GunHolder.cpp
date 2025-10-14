// Fill out your copyright notice in the Description page of Project Settings.


#include "GunHolder.h"


// Sets default values
AGunHolder::AGunHolder()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGunHolder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunHolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

