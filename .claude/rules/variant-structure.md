# Variant 구조 규칙

## 개요

이 프로젝트는 세 가지 독립적인 게임플레이 변형(Variant)을 가진다.
각 Variant는 동일한 구조 패턴을 따른다.

## 각 Variant의 구성 요소

| 컴포넌트 | Combat | Platforming | SideScrolling |
|----------|--------|-------------|----------------|
| Character | `CombatCharacter` | `PlatformingCharacter` | `SideScrollingCharacter` |
| GameMode | `CombatGameMode` | `PlatformingGameMode` | `SideScrollingGameMode` |
| PlayerController | `CombatPlayerController` | `PlatformingPlayerController` | `SideScrollingPlayerController` |
| AI | `CombatAIController`, `CombatEnemy` | - | `SideScrollingAIController`, `SideScrollingNPC` |
| UI | `CombatLifeBar` | - | `SideScrollingUI` |

## 베이스 클래스 계층

```
DDDCharacter
└── DDDPlayerCharacter
    ├── CombatCharacter
    ├── PlatformingCharacter
    └── SideScrollingCharacter

DDDGameMode
├── CombatGameMode
├── PlatformingGameMode
└── SideScrollingGameMode

DDDPlayerController
├── CombatPlayerController
├── PlatformingPlayerController
└── SideScrollingPlayerController
```

## 새 Variant 추가 시 패턴

1. `Source/DDD/Variant_<이름>/` 폴더 생성
2. `<이름>Character`, `<이름>GameMode`, `<이름>PlayerController` 구현
3. `DDD.Build.cs`의 `PublicIncludePaths`에 새 폴더들 등록
4. 필요에 따라 `AI/`, `Gameplay/`, `Interfaces/`, `UI/`, `Animation/` 하위 폴더 구성

## Variant 간 코드 공유

- 공통 로직은 `DDDCharacter`, `DDDGameMode`, `DDDPlayerController`에 구현
- Variant 간 직접 의존은 금지 — 공통 베이스나 인터페이스를 통해 소통
- 인터페이스 파일은 해당 Variant의 `Interfaces/` 폴더에 배치
