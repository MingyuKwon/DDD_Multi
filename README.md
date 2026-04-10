# DDD

Unreal Engine 5.7 기반 C++ 게임 프로젝트.  
턴제 전투 흐름을 FSM으로 관리하는 게임플레이 시스템을 구현합니다.

## 기술 스택

- **Engine**: Unreal Engine 5.7
- **Language**: C++
- **입력**: Enhanced Input System
- **AI**: StateTree + EQS
- **UI**: UMG
- **상태 관리**: 커스텀 FSM

## 소스 구조

```
Source/DDD/
├── Character/      # ADDDCharacter — 3인칭 카메라·이동·점프 베이스
├── Player/         # ADDDPlayerCharacter, ADDDPlayerController
├── GameMode/       # ADDDGameMode, ADDDGameplayMode (FSM 기반 게임 흐름)
└── DataStruct/     # FFiniteStateMachine, FFiniteState
```

## 문서

| 문서 | 설명 |
|------|------|
| [GameplayMode FSM](docs/gamemode.md) | 게임 흐름 상태 전이 다이어그램 및 각 상태 설명 |
| [FSM 시스템](docs/fsm.md) | FFiniteStateMachine / FFiniteState 구조 및 사용법 |

## 셋업

### 요구사항

- Unreal Engine 5.7
- Visual Studio 2022 (C++ 언리얼 개발 워크로드 포함)

### 방법

```bash
git clone <repo-url>
```

1. `DDD.uproject` 우클릭 → **Generate Visual Studio project files**
2. `DDD.sln`을 Visual Studio로 열고 빌드 (`Development Editor | Win64`)
3. `DDD.uproject`로 에디터 실행
