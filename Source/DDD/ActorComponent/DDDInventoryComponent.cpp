#include "ActorComponent/DDDInventoryComponent.h"

#include "DDDGameplayTags.h"
#include "Net/UnrealNetwork.h"

UDDDInventoryComponent::UDDDInventoryComponent()
{
    SetIsReplicatedByDefault(true);
}

void UDDDInventoryComponent::AddBullet(const FGameplayTag& BulletType, int32 Scale)
{
	FBulletItemEntry BulletEntry;
    BulletEntry.BulletType = BulletType;
    BulletEntry.Scale = Scale;  

    if (BulletType == TAG_Bullet_Damage)
    {
        DamageBulletsCylinder.Add(BulletEntry);
    }
    else
    {
        BuffBulletsCylinder.Add(BulletEntry);
    }
}


bool UDDDInventoryComponent::RemoveBullet(const FGameplayTag& BulletType, int32 Scale)
{
    FBulletItemEntry BulletEntry;
    BulletEntry.BulletType = BulletType;
    BulletEntry.Scale = Scale;

    if (BulletType == TAG_Bullet_Damage)
    {
        return DamageBulletsCylinder.RemoveSingle(BulletEntry) > 0;
    }
    else
    {
        return BuffBulletsCylinder.RemoveSingle(BulletEntry) > 0;
	}
}

void UDDDInventoryComponent::RotateCylinder(bool bDamageCylinder, bool bClockWise)
{
    TArray<FBulletItemEntry>& Cylinder = bDamageCylinder ? DamageBulletsCylinder : BuffBulletsCylinder;
	
    if (Cylinder.Num() > 0)
    {
        if (bClockWise)
        {
            FBulletItemEntry LastBullet = Cylinder.Last();
            Cylinder.RemoveAt(Cylinder.Num() - 1);
            Cylinder.Insert(LastBullet, 0);
        }
        else
        {
            FBulletItemEntry FirstBullet = Cylinder[0];
            Cylinder.RemoveAt(0);
            Cylinder.Add(FirstBullet);
        }
	}
}

FBulletItemEntry UDDDInventoryComponent::GetCurrentBullet(bool bDamageCylinder)
{
	TArray<FBulletItemEntry>& Cylinder = bDamageCylinder ? DamageBulletsCylinder : BuffBulletsCylinder;
    if (Cylinder.Num() > 0)
    {
        return Cylinder[0];
    }
	return FBulletItemEntry();
}

void UDDDInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UDDDInventoryComponent, DamageBulletsCylinder);
    DOREPLIFETIME(UDDDInventoryComponent, BuffBulletsCylinder);
}

void UDDDInventoryComponent::OnRep_DamageBulletsCylinder()
{
	OnInventoryChanged.Broadcast();
}

void UDDDInventoryComponent::OnRep_BuffBulletsCylinder()
{
    OnInventoryChanged.Broadcast();
}
