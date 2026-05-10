#pragma once
#include <string>

class Menus
{
private:
    static const int menuSize = 3;

    std::string mainMenu[menuSize];
    std::string inventoryMenu[menuSize];
    std::string shopMenu[menuSize];

public:
    Menus();

    std::string* GetMainMenu();
    std::string* GetInventoryMenu();
    std::string* GetShopMenu();
};