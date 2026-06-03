#pragma once
#include "Inventory.h"
#include "Wallet.h"

class Player
{
private:
    Inventory inventory;
    Wallet wallet;

public:
    Player(int startingGold = 100);

    Inventory& GetInventory();
    Wallet& GetWallet();

    const Inventory& GetInventory() const;
    const Wallet& GetWallet() const;
};