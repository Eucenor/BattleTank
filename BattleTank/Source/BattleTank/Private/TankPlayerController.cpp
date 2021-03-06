// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"




void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AIControlledTank = GetControlledTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp,Warning,TEXT("Tank not possessed"))
	}
	else
	{
		///UE_LOG(LogTemp, Warning, TEXT("Tank possessed by %s"),*AIControlledTank->GetName())
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

const ATank* ATankPlayerController::GetControlledTank()
{

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		GetControlledTank()->AimAt(OutHitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation)
{
	
	OutHitLocation = FVector(1.f);
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;

	if(GetLookDirection(ScreenLocation,LookDirection))
	{
		///UE_LOG(LogTemp, Warning, TEXT("direction:%s"), *LookDirection.ToString())
		GetLookVectorHitLocation(LookDirection,OutHitLocation);
	}
	return true;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector  CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
	
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Cast<AActor>(GetPawn()));
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		OutHitLocation= HitResult.Location;
		return true;
	}
	return false;
}