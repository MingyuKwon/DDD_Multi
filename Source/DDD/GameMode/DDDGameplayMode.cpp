// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/DDDGameplayMode.h"

#include "FiniteStateMachine.h"
#include "GameMode/DDDGameplayModeState.h"

void ADDDGameplayMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	InitFSM();
}

void ADDDGameplayMode::InitGameState()
{
	Super::InitGameState();
}

void ADDDGameplayMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void ADDDGameplayMode::StartPlay()
{
	Super::StartPlay();
	FSM->TransitState(EGameplayState::Begin);
}

void ADDDGameplayMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}

void ADDDGameplayMode::InitFSM()
{
	FSM = FFiniteStateMachine::Create();
	{
		TSharedPtr<FFiniteState> ReadyState = FSM->RegisterState(EGameplayState::Ready);
		ReadyState->AddTransition(EGameplayState::Begin);
		
		TSharedPtr<FFiniteState> BeginState = FSM->RegisterState(EGameplayState::Begin, MakeShared<FDDDGameplayModeState_Begin>());
		BeginState->AddTransition(EGameplayState::End);

		TSharedPtr<FFiniteState> EndState = FSM->RegisterState(EGameplayState::End, MakeShared<FDDDGameplayModeState_End>());
		EndState->AddTransition(EGameplayState::Ready);

	}

	FSM->SetFirstState(EGameplayState::Ready);
}
