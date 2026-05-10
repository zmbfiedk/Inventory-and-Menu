#pragma once
#include <string>

class Menus
{
private:
    static const int mainMenuSize = 3;
    static const int inventoryMenuSize = 3;
    static const int shopMenuSize = 3;

    std::string mainMenu[mainMenuSize];
    std::string inventoryMenu[inventoryMenuSize];
    std::string shopMenu[shopMenuSize];

public:
    Menus();

    std::string* GetMainMenu();
    std::string* GetInventoryMenu();
    std::string* GetShopMenu();

    int GetMainMenuSize();
    int GetInventoryMenuSize();
    int GetShopMenuSize();
};