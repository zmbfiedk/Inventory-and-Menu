#include "ItemFactory.h"
#include <random>

static int RandomInt(int min, int max)
{
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

static std::string Pick(const std::string* arr, int count)
{
    return arr[RandomInt(0, count - 1)];
}

Item ItemFactory::CreateRandomItem()
{
    int type = RandomInt(0, 3);

    if (type == 0)
    {
        const std::string names[] =
        {
            "Iron Sword", "Steel Blade", "Hunter Axe", "Bandit Knife",
            "Knight Broadsword", "War Cleaver", "Arena Spear", "Rusted Saber"
        };

        const std::string desc[] =
        {
            "A reliable melee weapon.",
            "Forged for battle.",
            "Deadly at close range.",
            "Simple, but effective."
        };

        return Item(
            Pick(names, 8),
            Pick(desc, 4),
            ItemType::Weapon,
            RandomInt(5, 20),
            0,
            0,
            RandomInt(25, 70)
        );
    }

    if (type == 1)
    {
        const std::string names[] =
        {
            "Healing Potion", "Stamina Potion", "Mana Potion", "Regen Potion",
            "Antidote Potion", "Adrenaline Flask", "Recovery Tonic", "Vital Elixir"
        };

        const std::string desc[] =
        {
            "Restores a bit of health.",
            "A quick consumable with a useful effect.",
            "Brewed for survival.",
            "Best used in emergencies."
        };

        return Item(
            Pick(names, 8),
            Pick(desc, 4),
            ItemType::Potion,
            0,
            RandomInt(10, 35),
            0,
            RandomInt(10, 40)
        );
    }

    if (type == 2)
    {
        const std::string names[] =
        {
            "Leather Armor", "Iron Armor", "Guard Vest", "Knight Plate",
            "Chain Mail", "Hunter Cloak", "Steel Chestplate", "Reinforced Pads"
        };

        const std::string desc[] =
        {
            "Protects the wearer from attacks.",
            "Basic defense gear.",
            "Heavy but sturdy.",
            "Reliable protection for combat."
        };

        return Item(
            Pick(names, 8),
            Pick(desc, 4),
            ItemType::Armor,
            0,
            0,
            RandomInt(2, 15),
            RandomInt(20, 60)
        );
    }

    const std::string names[] =
    {
        "Golden Ring", "Ancient Coin", "Gem Fragment", "Lucky Charm",
        "Old Relic", "Silver Idol", "Strange Talisman", "Merchant Token"
    };

    const std::string desc[] =
    {
        "Merchants still value it.",
        "A strange collectible item.",
        "Not useful in combat, but worth gold.",
        "Looks rare."
    };

    return Item(
        Pick(names, 8),
        Pick(desc, 4),
        ItemType::Trinket,
        0,
        0,
        0,
        RandomInt(5, 30)
    );
}