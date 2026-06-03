#pragma once
#include <vector>
#include "Item.h"

class World
{
private:
    std::vector<Item> sceneItems;

public:
    World();

    const std::vector<Item>& GetSceneItems() const;

    bool PickupItem(int index, class Inventory& inventory);
};