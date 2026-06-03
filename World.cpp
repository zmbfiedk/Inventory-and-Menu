#include "World.h"
#include "Inventory.h"
#include "ItemFactory.h"

World::World()
{
    for (int i = 0; i < 8; i++)
        sceneItems.push_back(ItemFactory::CreateRandomItem());
}

const std::vector<Item>& World::GetSceneItems() const
{
    return sceneItems;
}

bool World::PickupItem(int index, Inventory& inventory)
{
    if (index < 0 || index >= sceneItems.size())
        return false;

    inventory.AddItem(sceneItems[index]);

    sceneItems.erase(sceneItems.begin() + index);

    return true;
}