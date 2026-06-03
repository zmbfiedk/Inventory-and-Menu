#include "Shop.h"
#include "ItemFactory.h"

Shop::Shop()
{
    for (int i = 0; i < 8; i++)
        stock.push_back(ItemFactory::CreateRandomItem());
}

const std::vector<Item>& Shop::GetStock() const
{
    return stock;
}

int Shop::GetBuyPrice(const Item& item) const
{
    return item.GetBaseValue() + 10;
}

int Shop::GetSellPrice(const Item& item) const
{
    return item.GetBaseValue() / 2;
}

TransactionResult Shop::BuyItem(int index, Inventory& inventory, Wallet& wallet)
{
    if (index < 0 || index >= (int)stock.size())
        return TransactionResult::InvalidIndex;

    int price = GetBuyPrice(stock[index]);

    if (!wallet.SpendGold(price))
        return TransactionResult::NotEnoughGold;

    inventory.AddItem(stock[index]);
    stock.erase(stock.begin() + index);

    return TransactionResult::Success;
}

bool Shop::SellItem(int index, Inventory& inventory, Wallet& wallet)
{
    const Item* item = inventory.GetItem(index);

    if (!item)
        return false;

    int price = GetSellPrice(*item);

    wallet.AddGold(price);
    stock.push_back(*item);
    inventory.RemoveItem(index);

    return true;
}