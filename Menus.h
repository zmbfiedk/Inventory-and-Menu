#pragma once
#include <string>
#include "Menu.h"
#include "Item.h"

class Menus
{
private:
    Menu mainMenu;
    Menu inventoryMenu;
    Menu shopMenu;
    Item inventoryItems[3];

public:
    Menus();

    std::string GetMainMenuTitle();
    std::string GetInventoryMenuTitle();
    std::string GetShopMenuTitle();

    std::string* GetMainMenu();
    std::string* GetInventoryMenu();
    std::string* GetShopMenu();

    int GetMainMenuSize();
    int GetInventoryMenuSize();
    int GetShopMenuSize();
};