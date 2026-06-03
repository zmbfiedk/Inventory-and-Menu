#pragma once

class Wallet
{
private:
    int gold;

public:
    Wallet(int startingGold = 0);

    int GetGold() const;
    void AddGold(int amount);
    bool SpendGold(int amount);
};