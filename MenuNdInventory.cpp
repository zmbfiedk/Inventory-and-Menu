#include <iostream>
#include <conio.h>
#include "Cursor.h"
#include "MenuRenderer.h"
#include "Inventory.h"
#include "Shop.h"
#include "Wallet.h"

enum class MenuState
{
    Main,
    Inventory,
    Shop
};

int main()
{
    Wallet wallet(100);
    Inventory playerInventory;
    Shop shop;
    MenuRenderer renderer;
    Cursor cursor;

    const std::string mainMenu[] = { "Inventory", "Shop", "Exit" };
    MenuState state = MenuState::Main;
    bool running = true;

    while (running)
    {
        system("cls");

        if (state == MenuState::Main)
        {
            renderer.DrawMainMenu(mainMenu, 3, cursor.GetPosition(), wallet.GetGold());
        }
        else if (state == MenuState::Inventory)
        {
            renderer.DrawItemMenu(
                "Inventory",
                playerInventory.GetItems(),
                cursor.GetPosition(),
                wallet.GetGold(),
                false,
                playerInventory.GetSize(),
                playerInventory.GetTotalSellValue()
            );
        }
        else if (state == MenuState::Shop)
        {
            renderer.DrawItemMenu(
                "Shop",
                shop.GetStock(),
                cursor.GetPosition(),
                wallet.GetGold(),
                true,
                (int)shop.GetStock().size(),
                0
            );
        }

        int key = _getch();

        if (key == 224)
        {
            key = _getch();

            if (key == 72)
                cursor.Up();
            else if (key == 80)
            {
                if (state == MenuState::Main)
                    cursor.Down(3);
                else if (state == MenuState::Inventory)
                    cursor.Down(playerInventory.GetSize() + 1);
                else if (state == MenuState::Shop)
                    cursor.Down((int)shop.GetStock().size() + 1);
            }
        }
        else if (key == 13)
        {
            if (state == MenuState::Main)
            {
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
                    running = false;
                }
            }
            else if (state == MenuState::Inventory)
            {
                if (cursor.GetPosition() == playerInventory.GetSize())
                {
                    state = MenuState::Main;
                    cursor.Reset();
                }
                else
                {
                    playerInventory.GetItem(cursor.GetPosition());
                    if (playerInventory.GetSize() > 0)
                    {
                        shop.SellItem(cursor.GetPosition(), playerInventory, wallet);
                        cursor.Clamp(playerInventory.GetSize() + 1);
                    }
                }
            }
            else if (state == MenuState::Shop)
            {
                if (cursor.GetPosition() == (int)shop.GetStock().size())
                {
                    state = MenuState::Main;
                    cursor.Reset();
                }
                else
                {
                    shop.BuyItem(cursor.GetPosition(), playerInventory, wallet);
                    cursor.Clamp((int)shop.GetStock().size() + 1);
                }
            }
        }
    }

    return 0;
}