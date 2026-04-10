#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

/**
 * DDD 프로젝트에서 사용하는 Native Gameplay Tag 선언.
 * 소스코드에서 FDDDGameplayTags::Get().Ability_Minus 로 접근.
 *
 * 사용 예:
 *   FGameplayTagContainer Tags;
 *   Tags.AddTag(FDDDGameplayTags::Get().Ability_Minus);
 *
 *   if (AbilitySpec.DynamicAbilityTags.HasTag(FDDDGameplayTags::Get().Ability_Multiply))
 *   { ... }
 */

// ── Ability 태그 외부 선언 ────────────────────────────────────────────────────
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_State_Minus)
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_State_Divide)
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_State_Multiply)

/**
 * 싱글턴 구조체로 태그를 묶어 관리.
 * 태그가 추가될 때마다 이 구조체에 멤버를 추가한다.
 */
struct FDDDGameplayTags
{
    static const FDDDGameplayTags& Get()
    {
        static FDDDGameplayTags Instance;
        return Instance;
    }

    FGameplayTag State_Minus;
    FGameplayTag State_Divide;
    FGameplayTag State_Multiply;

private:
    FDDDGameplayTags();
};
