# FSM 시스템

`Source/DDD/DataStruct/` 에 위치한 커스텀 유한 상태 기계(Finite State Machine).  
`uint8` 로 캐스팅 가능한 `enum class` 를 StateID 로 사용합니다.

## 클래스 구조

```
FFiniteStateMachine   — FSM 본체 (TSharedFromThis)
└── FFiniteState      — 개별 상태 (TSharedFromThis)
```

## FFiniteStateMachine

### 생성

```cpp
TSharedPtr<FFiniteStateMachine> FSM = FFiniteStateMachine::Create(TEXT("MyFSM"));
```

서브클래스를 만들 경우 템플릿 인자로 지정:

```cpp
TSharedPtr<MyFSM> FSM = FFiniteStateMachine::Create<MyFSM>(TEXT("MyFSM"));
```

### 상태 등록 및 전이 설정

```cpp
TSharedPtr<FFiniteState> IdleState = FSM->RegisterState(EMyState::Idle);
IdleState->AddTransition(EMyState::Run);
IdleState->AddTransition(EMyState::Attack);

// 커스텀 상태 서브클래스 등록
TSharedPtr<FFiniteState> RunState = FSM->RegisterState(EMyState::Run, MakeShared<FMyRunState>(FSM));
RunState->AddTransition(EMyState::Idle);
```

### 콜백 바인딩

```cpp
IdleState->BindOnEnter(this, &AMyActor::OnEnterIdle);
IdleState->BindOnUpdate(this, &AMyActor::OnUpdateIdle);  // float DeltaSeconds
IdleState->BindOnExit(this, &AMyActor::OnExitIdle);
```

### 시작 및 매 틱 업데이트

```cpp
// 초기 상태 설정 (반드시 RegisterState 이후)
FSM->SetFirstState(EMyState::Idle);

// Tick
FSM->UpdateState(DeltaSeconds);
```

### 상태 전이

```cpp
// 외부에서 전이
FSM->TransitState(EMyState::Run);

// 상태 내부에서 전이 (FFiniteState 서브클래스 안)
TransitState(EMyState::Attack);
```

## FFiniteState 서브클래싱

```cpp
class FMyRunState : public FFiniteState
{
public:
    explicit FMyRunState(const TSharedPtr<FFiniteStateMachine>& Owner)
        : FFiniteState(Owner) {}

protected:
    virtual void OnEnterImpl() override { /* ... */ }
    virtual void OnUpdateImpl(float DeltaSeconds) override { /* ... */ }
    virtual void OnExitImpl() override { /* ... */ }
};
```

## 주요 특성

- **지연 전이(Deferred Transition)**: `OnEnter` / `OnUpdate` / `OnExit` 실행 중 요청된 전이는 큐에 쌓였다가 현재 콜백 완료 후 처리됨
- **전이 제한**: 한 프레임에 최대 16회 연속 전이, 초과 시 `ensure` 발생
- **허용 전이 검사**: `AddTransition` 으로 등록되지 않은 목적지로의 전이는 자동 거부

## 관련 파일

- `Source/DDD/DataStruct/FiniteStateMachine.h/.cpp`
- `Source/DDD/DataStruct/FiniteState.h/.cpp`
