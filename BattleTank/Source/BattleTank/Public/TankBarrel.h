// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))

class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	///-1 is max downowrd speed and +1 one vice versa
	void Elevate(float RelativeSpeed);
	UPROPERTY(EditAnywhere,Category=Setup)
	float MaxDegreesPerSecond = 20.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 40.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0.f;
	
};