#include "Shop.h"
#include "ItemFactory.h"
#include <algorithm>

Shop::Shop()
{
    for (int i = 0; i < 6; i++)
        stock.push_back(ItemFactory::CreateRandomItem());
}

const std::vector<Item>& Shop::GetStock() const
{
    return stock;
}

int Shop::GetBuyPrice(const Item& item) const
{
    return std::max(1, (item.GetBaseValue() * 3) / 2);
}

int Shop::GetSellPrice(const Item& item) const
{
    return std::max(1, item.GetBaseValue() / 2);
}

bool Shop::BuyItem(int index, Inventory& playerInventory, Wallet& wallet)
{
    if (index < 0 || index >= (int)stock.size())
        return false;

    int price = GetBuyPrice(stock[index]);
    if (!wallet.SpendGold(price))
        return false;

    playerInventory.AddItem(stock[index]);
    stock.erase(stock.begin() + index);
    return true;
}

bool Shop::SellItem(int index, Inventory& playerInventory, Wallet& wallet)
{
    const Item* item = playerInventory.GetItem(index);
    if (!item)
        return false;

    int price = GetSellPrice(*item);
    wallet.AddGold(price);
    stock.push_back(*item);
    return playerInventory.RemoveItem(index);
}