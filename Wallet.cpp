#include "Wallet.h"

Wallet::Wallet(int startingGold)
    : gold(startingGold)
{
}

int Wallet::GetGold() const
{
    return gold;
}

void Wallet::AddGold(int amount)
{
    if (amount > 0)
        gold += amount;
}

bool Wallet::SpendGold(int amount)
{
    if (amount <= 0 || gold < amount)
        return false;

    gold -= amount;
    return true;
}