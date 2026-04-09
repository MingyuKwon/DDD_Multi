# DDD

DDD의 멀티플레이어 버전 프로젝트입니다.

## 개요

기존 DDD를 기반으로 멀티플레이어를 지원하도록 재설계한 Unreal Engine 프로젝트입니다.  
언리얼의 **Gameplay Ability System(GAS)** 을 적극적으로 활용하여 능력, 스탯, 효과 시스템을 구성합니다.

## 기술 스택

- **Engine**: Unreal Engine 5.7
- **Language**: C++
- **핵심 시스템**: Gameplay Ability System (GAS)
- **입력**: Enhanced Input System
- **AI**: StateTree + EQS
- **UI**: UMG

## 소스 구조

```
Source/DDD/
├── Character/              # 공통 베이스 캐릭터
├── Player/                 # 공통 플레이어 캐릭터 / 컨트롤러
└── GameMode/               # 공통 게임모드
```

## 시작하기

### 요구사항

- Unreal Engine 5.7
- Visual Studio 2022 (C++ 언리얼 개발 워크로드 포함)

### 셋업

```bash
git clone <repo-url>
```

1. `DDD.uproject` 우클릭 → **Generate Visual Studio project files**
2. `DDD.sln`을 Visual Studio로 열고 빌드
3. `DDD.uproject`로 에디터 실행
