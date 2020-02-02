// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

# pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
class UTankBarrel;
class UTankTurret;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void AimAt(FVector HitLocation,float LaunchSpeed);
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void MoveBarrelTowards(FVector AimDirection);
	void SetTurretReference(UTankTurret* TurretToSet);
};