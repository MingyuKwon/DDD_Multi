#pragma once

#include "CoreMinimal.h"
#include "FiniteState.h"

/**
 * ADDDGameplayMode FSM 전용 상태 베이스.
 * Begin / End 상태가 공통으로 필요한 기능이 생기면 여기에 추가.
 */
class FDDDGameplayModeState : public FFiniteState
{

};

/**
 * 게임플레이가 본격적으로 시작되는 상태.
 * Ready → Begin 전이 시 진입, 게임 종료 조건 충족 시 End 로 전이.
 */
class FDDDGameplayModeState_Begin : public FDDDGameplayModeState
{
protected:
	virtual void OnEnterImpl() override;
	virtual void OnUpdateImpl(float DeltaSeconds) override;
	virtual void OnExitImpl() override;
};

/**
 * 게임이 종료된 상태.
 * Begin → End 전이 시 진입, 결과 처리 후 Ready 로 복귀 가능.
 */
class FDDDGameplayModeState_End : public FDDDGameplayModeState
{
protected:
	virtual void OnEnterImpl() override;
	virtual void OnUpdateImpl(float DeltaSeconds) override;
	virtual void OnExitImpl() override;
};
