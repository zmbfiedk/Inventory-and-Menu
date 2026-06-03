#include "Item.h"

Item::Item()
{
    name = "Unknown";
    description = "";
    type = ItemType::Trinket;

    damage = 0;
    heal = 0;
    defense = 0;

    baseValue = 0;
}

Item::Item(
    const std::string& name,
    const std::string& description,
    ItemType type,
    int damage,
    int heal,
    int defense,
    int baseValue
)
{
    this->name = name;
    this->description = description;
    this->type = type;

    this->damage = damage;
    this->heal = heal;
    this->defense = defense;

    this->baseValue = baseValue;
}

std::string Item::GetName() const
{
    return name;
}

std::string Item::GetDescription() const
{
    return description;
}

ItemType Item::GetType() const
{
    return type;
}

int Item::GetBaseValue() const
{
    return baseValue;
}

std::string Item::GetTypeText() const
{
    switch (type)
    {
    case ItemType::Weapon:
        return "Weapon";

    case ItemType::Potion:
        return "Potion";

    case ItemType::Armor:
        return "Armor";

    case ItemType::Trinket:
        return "Trinket";

    default:
        return "Unknown";
    }
}

std::string Item::GetStatsText() const
{
    switch (type)
    {
    case ItemType::Weapon:
        return "Damage: " + std::to_string(damage);

    case ItemType::Potion:
        return "Heal: " + std::to_string(heal);

    case ItemType::Armor:
        return "Defense: " + std::to_string(defense);

    case ItemType::Trinket:
        return "No stats";

    default:
        return "";
    }
}