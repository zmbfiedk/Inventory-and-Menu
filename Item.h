#pragma once
#include <string>
#include "ItemType.h"

class Item
{
private:
    std::string name;
    std::string description;
    ItemType type;
    int damage;
    int heal;
    int defense;
    int baseValue;

public:
    Item();
    Item(const std::string& name, const std::string& description, ItemType type,
        int damage, int heal, int defense, int baseValue);

    const std::string& GetName() const;
    const std::string& GetDescription() const;
    ItemType GetType() const;
    std::string GetTypeName() const;

    int GetDamage() const;
    int GetHeal() const;
    int GetDefense() const;
    int GetBaseValue() const;

    std::string GetStatsText() const;
};