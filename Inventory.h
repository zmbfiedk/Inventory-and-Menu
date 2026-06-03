#pragma once
#include <vector>
#include "Item.h"

class Inventory
{
private:
    std::vector<Item> items;

public:
    void AddItem(const Item& item);
    bool RemoveItem(int index);
    const Item* GetItem(int index) const;

    int GetSize() const;
    int GetTotalSellValue() const;

    const std::vector<Item>& GetItems() const;
};