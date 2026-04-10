# GameplayMode FSM

`ADDDGameplayMode`가 소유하는 FSM으로 게임 한 판의 흐름을 제어합니다.

## 상태 전이

```
Ready ──► Begin ──► PlayerTurn ◄──► EnemyTurn
                        │                │
                    PlayerWin        EnemyWin
                        └──────┬──────┘
                               ▼
                              End ──► Ready
```

## 상태 목록

| 상태 | 클래스 | 설명 |
|------|--------|------|
| `Ready` | `FFiniteState` (기본) | 게임 시작 대기. `StartPlay` 시 `Begin` 으로 전이 |
| `Begin` | `FDDDGameplayModeState_Begin` | 초기화 후 즉시 `PlayerTurn` 으로 전이 |
| `PlayerTurn` | `FDDDGameplayModeState_PlayerTurn` | 플레이어 행동 처리 |
| `EnemyTurn` | `FDDDGameplayModeState_EnemyTurn` | 적 행동 처리 |
| `PlayerWin` | `FDDDGameplayModeState_PlayerWin` | 플레이어 승리 처리 후 `End` 로 전이 |
| `EnemyWin` | `FDDDGameplayModeState_EnemyWin` | 적 승리 처리 후 `End` 로 전이 |
| `End` | `FDDDGameplayModeState_End` | 결과 정산, `Ready` 로 복귀 가능 |

## 허용 전이 테이블

| From | To |
|------|----|
| Ready | Begin |
| Begin | PlayerTurn |
| PlayerTurn | EnemyTurn, PlayerWin, EnemyWin |
| EnemyTurn | PlayerTurn, EnemyTurn, PlayerWin, EnemyWin |
| PlayerWin | End |
| EnemyWin | End |
| End | Ready |

## 관련 파일

- `Source/DDD/GameMode/DDDGameplayMode.h/.cpp`
- `Source/DDD/GameMode/DDDGameplayModeState.h/.cpp`
