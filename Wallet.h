#pragma once

class Wallet
{
private:
    int gold;

public:
    Wallet(int startingGold);

    int GetGold() const;

    void AddGold(int amount);

    bool SpendGold(int amount);
};