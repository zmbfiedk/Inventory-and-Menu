#include "ItemFactory.h"
#include <random>

static int RandInt(int min, int max)
{
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

static std::string Pick(const std::string* arr, int count)
{
    return arr[RandInt(0, count - 1)];
}

Item ItemFactory::CreateRandomItem()
{
    int roll = RandInt(0, 3);

    if (roll == 0)
    {
        const std::string names[] = { "Iron Sword", "Axe", "Dagger", "Blade" };
        std::string name = Pick(names, 4);
        int dmg = RandInt(5, 20);
        int value = RandInt(25, 70);

        return Item(
            name,
            "A weapon used to deal damage.",
            ItemType::Weapon,
            dmg, 0, 0, value
        );
    }

    if (roll == 1)
    {
        const std::string names[] = { "Healing Potion", "Mana Potion", "Regen Potion", "Stamina Potion" };
        std::string name = Pick(names, 4);
        int heal = RandInt(10, 35);
        int value = RandInt(10, 40);

        return Item(
            name,
            "A consumable item with a useful effect.",
            ItemType::Potion,
            0, heal, 0, value
        );
    }

    if (roll == 2)
    {
        const std::string names[] = { "Leather Armor", "Iron Armor", "Knight Plate", "Guard Vest" };
        std::string name = Pick(names, 4);
        int def = RandInt(2, 15);
        int value = RandInt(20, 60);

        return Item(
            name,
            "Protective gear that reduces damage.",
            ItemType::Armor,
            0, 0, def, value
        );
    }

    const std::string names[] = { "Lucky Coin", "Gem Fragment", "Ancient Relic", "Odd Charm" };
    std::string name = Pick(names, 4);
    int value = RandInt(5, 25);

    return Item(
        name,
        "A strange object merchants still buy.",
        ItemType::Trinket,
        0, 0, 0, value
    );
}