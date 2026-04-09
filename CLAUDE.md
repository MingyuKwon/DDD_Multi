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

## 작업 시 주의사항

- `.sln` 파일은 gitignore됨 → `DDD.uproject` 우클릭 → "Generate Visual Studio project files"로 재생성
- `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`는 gitignore됨 (빌드 시 자동 생성)
- 새 C++ 클래스 추가 시 `DDD.Build.cs`의 `PublicIncludePaths`에 폴더 경로 추가 필요
