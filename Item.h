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

    Item(
        const std::string& name,
        const std::string& description,
        ItemType type,
        int damage,
        int heal,
        int defense,
        int baseValue
    );

    std::string GetName() const;
    std::string GetDescription() const;
    std::string GetStatsText() const;
    std::string GetTypeText() const;

    ItemType GetType() const;

    int GetBaseValue() const;
};