#include "GameMode/DDDGameplayModeState.h"
#include "DDDLog.h"
#include "FiniteStateMachine.h"

// ── Begin ────────────────────────────────────────────────────────────────────

void FDDDGameplayModeState_Begin::OnEnterImpl()
{
	DDD_LOG(LogFSM, Log, TEXT("Entering Begin State"));
}

void FDDDGameplayModeState_Begin::OnUpdateImpl(float DeltaSeconds)
{
}

void FDDDGameplayModeState_Begin::OnExitImpl()
{
}

// ── End ──────────────────────────────────────────────────────────────────────

void FDDDGameplayModeState_End::OnEnterImpl()
{
	DDD_LOG(LogFSM, Log, TEXT("Entering End State"));
}

void FDDDGameplayModeState_End::OnUpdateImpl(float DeltaSeconds)
{
}

void FDDDGameplayModeState_End::OnExitImpl()
{
}
