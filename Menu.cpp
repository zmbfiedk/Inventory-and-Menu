#include "Menus.h"

Menus::Menus()
{
    mainMenu[0] = "Inventory";
    mainMenu[1] = "Shop";
    mainMenu[2] = "Exit";

    inventoryMenu[0] = "Sword";
    inventoryMenu[1] = "Potion";
    inventoryMenu[2] = "Back";

    shopMenu[0] = "Buy";
    shopMenu[1] = "Sell";
    shopMenu[2] = "Back";
}

std::string* Menus::GetMainMenu()
{
    return mainMenu;
}

std::string* Menus::GetInventoryMenu()
{
    return inventoryMenu;
}

std::string* Menus::GetShopMenu()
{
    return shopMenu;
}

int Menus::GetMainMenuSize()
{
    return mainMenuSize;
}

int Menus::GetInventoryMenuSize()
{
    return inventoryMenuSize;
}

int Menus::GetShopMenuSize()
{
    return shopMenuSize;
}