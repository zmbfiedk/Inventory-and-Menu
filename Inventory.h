#pragma once
#include <vector>
#include "Item.h"

class Inventory
{
private:
    std::vector<Item> items;

public:
    void AddItem(const Item& item);

    void RemoveItem(int index);

    int GetSize() const;

    const std::vector<Item>& GetItems() const;

    const Item* GetItem(int index) const;

    int GetTotalSellValue() const;
};