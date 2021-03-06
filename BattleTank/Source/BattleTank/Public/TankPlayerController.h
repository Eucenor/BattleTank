// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
    const ATank* GetControlledTank() ;
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    void AimTowardsCrosshair();
    bool GetSightRayHitLocation(FVector& OutHitVector);
    bool GetLookDirection(FVector2D ScreenLocation, FVector& Direction) const;
    bool GetLookVectorHitLocation(FVector& LookDirection, FVector& HitLocation) const;
    UPROPERTY(EditAnywhere)
        float CrossHairXLocation = 0.5f;
    UPROPERTY(EditAnywhere)
        float CrossHairYLocation = 0.33333f;
    UPROPERTY(EditAnywhere)
        float LineTraceRange = 1000000.f;
};
