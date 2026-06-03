#include "Inventory.h"

void Inventory::AddItem(const Item& item)
{
    items.push_back(item);
}

bool Inventory::RemoveItem(int index)
{
    if (index < 0 || index >= (int)items.size())
        return false;

    items.erase(items.begin() + index);
    return true;
}

const Item* Inventory::GetItem(int index) const
{
    if (index < 0 || index >= (int)items.size())
        return nullptr;

    return &items[index];
}

int Inventory::GetSize() const
{
    return (int)items.size();
}

int Inventory::GetTotalSellValue() const
{
    int total = 0;
    for (const Item& item : items)
        total += item.GetBaseValue() / 2;
    return total;
}

const std::vector<Item>& Inventory::GetItems() const
{
    return items;
}