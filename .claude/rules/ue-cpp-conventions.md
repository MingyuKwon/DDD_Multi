# Unreal Engine C++ 코딩 규칙

## 클래스 접두사

| 접두사 | 기반 클래스 | 예시 |
|--------|-------------|------|
| `A` | AActor | `ACombatEnemy` |
| `U` | UObject | `UCombatLifeBar` |
| `F` | struct | `FAttackData` |
| `E` | enum class | `ECombatState` |
| `I` | Interface | `ICombatDamageable` |

## 헤더 구조

```cpp
#pragma once

#include "CoreMinimal.h"
#include "ParentClass.h"
#include "ClassName.generated.h"  // 항상 마지막 include

UCLASS()
class DDD_API AClassName : public AParentClass
{
    GENERATED_BODY()
public:
    // ...
};
```

## UPROPERTY / UFUNCTION 규칙

- 블루프린트에서 읽고 쓸 경우: `UPROPERTY(EditAnywhere, BlueprintReadWrite)`
- 블루프린트에서 읽기만: `UPROPERTY(VisibleAnywhere, BlueprintReadOnly)`
- 에디터에서만 편집: `UPROPERTY(EditDefaultsOnly)`
- 블루프린트에서 호출 가능: `UFUNCTION(BlueprintCallable)`
- 블루프린트에서 오버라이드 가능: `UFUNCTION(BlueprintNativeEvent)`

## 새 클래스 추가 시 체크리스트

1. 파일 위치: 기능에 맞는 Variant 폴더 안에 배치
2. `DDD.Build.cs`의 `PublicIncludePaths`에 새 폴더가 없으면 추가
3. 헤더에 `DDD_API` 매크로 포함 확인
4. `.generated.h`는 항상 마지막 include

## 금지 사항

- `#include "EngineGlobalIncludes.h"` — 빌드 시간 증가, 사용 금지
- 로우 포인터로 UObject 참조 — `UPROPERTY()` 또는 `TWeakObjectPtr` 사용
- `delete`로 UObject 해제 — UE GC에 맡길 것
