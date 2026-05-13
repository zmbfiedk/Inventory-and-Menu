#include "Menus.h"
#include <vector>

Menus::Menus()
{
    inventoryItems[0] = Item("Sword");
    inventoryItems[1] = Item("Potion");
    inventoryItems[2] = Item("Shield");

    mainMenu = Menu("Main Menu", { "Inventory", "Shop", "Exit" });
    inventoryMenu = Menu(
        "Inventory",
        {
            inventoryItems[0].GetName(),
            inventoryItems[1].GetName(),
            inventoryItems[2].GetName(),
            "Back"
        }
    );
    shopMenu = Menu("Shop", { "Buy", "Sell", "Back" });
}

std::string Menus::GetMainMenuTitle()
{
    return mainMenu.GetTitle();
}

std::string Menus::GetInventoryMenuTitle()
{
    return inventoryMenu.GetTitle();
}

std::string Menus::GetShopMenuTitle()
{
    return shopMenu.GetTitle();
}

std::string* Menus::GetMainMenu()
{
    return mainMenu.GetOptions();
}

std::string* Menus::GetInventoryMenu()
{
    return inventoryMenu.GetOptions();
}

std::string* Menus::GetShopMenu()
{
    return shopMenu.GetOptions();
}

int Menus::GetMainMenuSize()
{
    return mainMenu.GetSize();
}

int Menus::GetInventoryMenuSize()
{
    return inventoryMenu.GetSize();
}

int Menus::GetShopMenuSize()
{
    return shopMenu.GetSize();
}