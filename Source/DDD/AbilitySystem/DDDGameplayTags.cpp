#include "AbilitySystem/DDDGameplayTags.h"

// ── 태그 정의 (문자열이 실제 태그 이름) ──────────────────────────────────────
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Minus,    "DDD.State.Minus")
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Divide,   "DDD.State.Divide")
UE_DEFINE_GAMEPLAY_TAG(TAG_State_Multiply, "DDD.State.Multiply")

FDDDGameplayTags::FDDDGameplayTags()
{
    State_Minus    = TAG_State_Minus;
    State_Divide   = TAG_State_Divide;    
    State_Multiply = TAG_State_Multiply;
}
