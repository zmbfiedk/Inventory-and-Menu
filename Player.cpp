#include "Player.h"

Player::Player(int startingGold)
    : wallet(startingGold)
{
}

Inventory& Player::GetInventory()
{
    return inventory;
}

Wallet& Player::GetWallet()
{
    return wallet;
}

const Inventory& Player::GetInventory() const
{
    return inventory;
}

const Wallet& Player::GetWallet() const
{
    return wallet;
}