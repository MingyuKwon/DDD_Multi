#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "DDDInventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FBulletItemEntry
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FGameplayTag BulletType;

    UPROPERTY(BlueprintReadOnly)
    int32 Scale = 0;

    bool IsValid() const
    {
        return BulletType.IsValid() && Scale > 0;
	}

    bool operator==(const FBulletItemEntry& Other) const
    {
		return BulletType == Other.BulletType && Scale == Other.Scale;
    }
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryChanged);

UCLASS(ClassGroup = "DDD", meta = (BlueprintSpawnableComponent))
class DDD_API UDDDInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDDDInventoryComponent();

	void AddBullet(const FGameplayTag& BulletType, int32 Scale);
    bool RemoveBullet(const FGameplayTag& BulletType, int32 Scale);

    void RotateCylinder(bool bDamageCylinder, bool bClockWise);
    FBulletItemEntry GetCurrentBullet(bool bDamageCylinder);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(BlueprintAssignable, Category = "Inventory")
    FOnInventoryChanged OnInventoryChanged;

private:
    UPROPERTY(ReplicatedUsing = OnRep_DamageBulletsCylinder)
    TArray<FBulletItemEntry> DamageBulletsCylinder;

    UPROPERTY(ReplicatedUsing = OnRep_BuffBulletsCylinder)
    TArray<FBulletItemEntry> BuffBulletsCylinder;

    UFUNCTION()
    void OnRep_DamageBulletsCylinder();

	UFUNCTION()
    void OnRep_BuffBulletsCylinder();
};
