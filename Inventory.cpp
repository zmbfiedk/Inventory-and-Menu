#include "Inventory.h"

void Inventory::AddItem(const Item& item)
{
    items.push_back(item);
}

void Inventory::RemoveItem(int index)
{
    items.erase(items.begin() + index);
}

int Inventory::GetSize() const
{
    return (int)items.size();
}

const std::vector<Item>& Inventory::GetItems() const
{
    return items;
}

const Item* Inventory::GetItem(int index) const
{
    if (index < 0 || index >= items.size())
        return nullptr;

    return &items[index];
}

int Inventory::GetTotalSellValue() const
{
    int total = 0;

    for (const Item& item : items)
    {
        total += item.GetBaseValue() / 2;
    }

    return total;
}