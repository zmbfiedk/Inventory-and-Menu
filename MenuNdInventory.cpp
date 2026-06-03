#include <iostream>
#include <conio.h>

#include "Cursor.h"
#include "Inventory.h"
#include "MenuRenderer.h"
#include "Shop.h"
#include "Wallet.h"
#include "World.h"
#include "TransactionResult.h"

enum class MenuState
{
    Main,
    Inventory,
    Shop,
    WorldItems
};

int main()
{
    Wallet wallet(100);
    Inventory inventory;
    Shop shop;
    World world;
    Cursor cursor;
    MenuRenderer renderer;

    bool running = true;
    MenuState state = MenuState::Main;

    std::string statusMessage;

    const std::string mainMenu[] =
    {
        "Inventory",
        "Shop",
        "Scene Items",
        "Exit"
    };

    while (running)
    {
        system("cls");

        switch (state)
        {
        case MenuState::Main:
            renderer.DrawMainMenu(mainMenu, 4, cursor.GetPosition(), wallet.GetGold());
            break;

        case MenuState::Inventory:
            renderer.DrawItemMenu(
                "INVENTORY",
                inventory.GetItems(),
                cursor.GetPosition(),
                false,
                wallet.GetGold(),
                statusMessage
            );
            break;

        case MenuState::Shop:
            renderer.DrawItemMenu(
                "SHOP",
                shop.GetStock(),
                cursor.GetPosition(),
                true,
                wallet.GetGold(),
                statusMessage
            );
            break;

        case MenuState::WorldItems:
            renderer.DrawItemMenu(
                "SCENE ITEMS",
                world.GetSceneItems(),
                cursor.GetPosition(),
                false,
                wallet.GetGold(),
                statusMessage
            );
            break;
        }

        statusMessage.clear();

        int key = _getch();

        if (key == 224)
        {
            key = _getch();

            if (key == 72)
                cursor.MoveUp();

            if (key == 80)
            {
                switch (state)
                {
                case MenuState::Main:
                    cursor.MoveDown(4);
                    break;

                case MenuState::Inventory:
                    cursor.MoveDown(inventory.GetSize() + 1);
                    break;

                case MenuState::Shop:
                    cursor.MoveDown((int)shop.GetStock().size() + 1);
                    break;

                case MenuState::WorldItems:
                    cursor.MoveDown((int)world.GetSceneItems().size() + 1);
                    break;
                }
            }
        }
        else if (key == 13)
        {
            switch (state)
            {
            case MenuState::Main:
                if (cursor.GetPosition() == 0)
                {
                    state = MenuState::Inventory;
                    cursor.Reset();
                }
                else if (cursor.GetPosition() == 1)
                {
                    state = MenuState::Shop;
                    cursor.Reset();
                }
                else if (cursor.GetPosition() == 2)
                {
                    state = MenuState::WorldItems;
                    cursor.Reset();
                }
                else if (cursor.GetPosition() == 3)
                {
                    running = false;
                }
                break;

            case MenuState::Inventory:
                if (cursor.GetPosition() == inventory.GetSize())
                {
                    state = MenuState::Main;
                    cursor.Reset();
                }
                else if (inventory.GetSize() > 0)
                {
                    if (shop.SellItem(cursor.GetPosition(), inventory, wallet))
                        statusMessage = "Item sold.";
                    cursor.Clamp(inventory.GetSize() + 1);
                }
                break;

            case MenuState::Shop:
                if (cursor.GetPosition() == (int)shop.GetStock().size())
                {
                    state = MenuState::Main;
                    cursor.Reset();
                }
                else
                {
                    TransactionResult result = shop.BuyItem(cursor.GetPosition(), inventory, wallet);

                    if (result == TransactionResult::Success)
                    {
                        statusMessage = "Item bought.";
                        cursor.Clamp((int)shop.GetStock().size() + 1);
                    }
                    else if (result == TransactionResult::NotEnoughGold)
                    {
                        statusMessage = "You don't have enough money.";
                    }
                    else
                    {
                        statusMessage = "That item is unavailable.";
                    }
                }
                break;

            case MenuState::WorldItems:
                if (cursor.GetPosition() == (int)world.GetSceneItems().size())
                {
                    state = MenuState::Main;
                    cursor.Reset();
                }
                else
                {
                    if (world.PickupItem(cursor.GetPosition(), inventory))
                        statusMessage = "Item picked up.";

                    cursor.Clamp((int)world.GetSceneItems().size() + 1);
                }
                break;
            }
        }
        else if (key == 8)
        {
            state = MenuState::Main;
            cursor.Reset();
        }
    }

    return 0;
}