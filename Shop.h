#pragma once
#include <vector>
#include "Item.h"
#include "Inventory.h"
#include "Wallet.h"
#include "TransactionResult.h"

class Shop
{
private:
    std::vector<Item> stock;

public:
    Shop();

    const std::vector<Item>& GetStock() const;

    int GetBuyPrice(const Item& item) const;
    int GetSellPrice(const Item& item) const;

    TransactionResult BuyItem(int index, Inventory& inventory, Wallet& wallet);
    bool SellItem(int index, Inventory& inventory, Wallet& wallet);
};