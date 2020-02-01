// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AIControlledTank = GetAIControlledTank();
	auto PlayerControlledTank = GetPlayerTank();
	///checking null for AIControlledTank
	if (!AIControlledTank)
	{
		///UE_LOG(LogTemp, Warning, TEXT("(inside AITankController) AITank not possessed"))
	}
	else
	{
		///UE_LOG(LogTemp, Warning, TEXT("(inside AITankController) AITank %s possessed"), *AIControlledTank->GetName());
	}
	///Checking null for PlayerControlledTank
	
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerControlledTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerControlledTank)
	{
		///UE_LOG(LogTemp, Warning, TEXT("(inside AITankController) Player Tank not possessed"))
	}
	else
	{
		///UE_LOG(LogTemp, Warning, TEXT("(inside AITankController) Player Tank %s possessed"), *PlayerControlledTank->GetName());
	}
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto OurTankName = GetName();
	if (GetPlayerTank())
	{	
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());		///move towards player
		/// aim towards player
	///fire ifr ready
	}
}
