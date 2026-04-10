# DDD — Unreal Engine 5.7 프로젝트

## 프로젝트 개요

Unreal Engine 5.7 기반 C++ 게임 프로젝트. 단일 모듈(`DDD`) 안에 세 가지 독립적인 게임플레이 변형(Variant)이 공존하는 구조.

## 엔진 & 모듈 정보

- **Engine**: Unreal Engine 5.7
- **Module**: `DDD` (Runtime)
- **주요 의존성**: `EnhancedInput`, `AIModule`, `StateTreeModule`, `GameplayStateTreeModule`, `UMG`, `Slate`
- **플러그인**: StateTree, GameplayStateTree, ModelingToolsEditorMode

## 소스 구조

```
Source/DDD/
├── Character/          # 공통 베이스 캐릭터 (DDDCharacter)
├── Player/             # 공통 플레이어 (DDDPlayerCharacter, DDDPlayerController)
├── GameMode/           # 공통 게임모드 (DDDGameMode)
│
├── Variant_Combat/         # 전투 변형
│   ├── AI/                 # CombatAIController, CombatEnemy, EQS 컨텍스트, StateTree 유틸
│   ├── Animation/          # AnimNotify (콤보 체크, 어택 트레이스, 차지 어택)
│   ├── Gameplay/           # ActivationVolume, CheckpointVolume, DamageableBox, Dummy, LavaFloor
│   ├── Interfaces/         # CombatActivatable, CombatAttacker, CombatDamageable
│   └── UI/                 # CombatLifeBar
│
├── Variant_Platforming/    # 플랫포밍 변형
│   └── Animation/          # AnimNotify_EndDash
│
└── Variant_SideScrolling/  # 사이드스크롤 변형
    ├── AI/                 # SideScrollingAIController, NPC, StateTree 유틸
    ├── Gameplay/           # JumpPad, MovingPlatform, Pickup, SoftPlatform
    ├── Interfaces/         # SideScrollingInteractable
    └── UI/                 # SideScrollingUI
```

## 아키텍처 패턴

- 각 Variant는 자체 **Character**, **GameMode**, **PlayerController**를 가짐
- 공통 베이스 클래스(`DDD` 접두사)를 상속받아 Variant별로 확장
- AI는 **StateTree** + **EQS** 조합 사용
- 입력은 **Enhanced Input System** 사용
- UI는 **UMG** (UserWidget 기반)

## 네이밍 컨벤션

UE 표준 규칙을 따름:
- 클래스 접두사: `A`(Actor), `U`(UObject), `F`(struct), `E`(enum), `I`(Interface)
- 파일명 = 클래스명 (접두사 포함): `CombatEnemy.h` → `ACombatEnemy`
- Variant 클래스는 `Combat`, `Platforming`, `SideScrolling` 접두사 사용

## Claude 행동 규칙

- 파일을 읽을 때는 별도로 묻지 않고 바로 진행한다.

### README 구조 규칙

README는 루트 하나로 끝내지 않고 계층형 구조를 유지한다.

```
README.md                          # 루트 — 프로젝트 개요 + 하위 README 링크 목록
docs/
├── gamemode.md                    # GameplayMode FSM 흐름 상세
├── fsm.md                         # FFiniteStateMachine / FFiniteState 사용법
└── (시스템이 추가될 때마다 파일 추가)
```

- **루트 `README.md`**: 프로젝트 한 줄 소개, 기술 스택, 소스 구조, 셋업 방법, `docs/` 링크 목록만 포함. 상세 설명은 쓰지 않는다.
- **`docs/*.md`**: 각 시스템의 상세 설명, 다이어그램, API 예시를 담는다. 파일명은 시스템명을 소문자로.
- 새 시스템이 추가되면 `docs/` 에 해당 파일을 만들고 루트 `README.md` 링크 목록에 추가한다.
- README.md 갱신 시 Variant(`Variant_Combat`, `Variant_Platforming`, `Variant_SideScrolling`) 관련 구조·설명은 포함하지 않는다.

## 작업 시 주의사항

- `.sln` 파일은 gitignore됨 → `DDD.uproject` 우클릭 → "Generate Visual Studio project files"로 재생성
- `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`는 gitignore됨 (빌드 시 자동 생성)
- 새 C++ 클래스 추가 시 `DDD.Build.cs`의 `PublicIncludePaths`에 폴더 경로 추가 필요
