#include <iostream>
#include <conio.h>
#include "Menus.h"
#include "DrawCurrentMenu.h"
#include "Pointer.h"

enum MenuState
{
    MAIN,
    INVENTORY,
    SHOP
};

int main()
{
    Menus menus;
    DrawCurrentMenu drawer;
    Pointer pointer;

    MenuState currentMenu = MAIN;
    bool running = true;

    while (running)
    {
        system("cls");

        switch (currentMenu)
        {
        case MAIN:
            std::cout << menus.GetMainMenuTitle() << "\n\n";
            drawer.DrawMenu(
                menus.GetMainMenu(),
                menus.GetMainMenuSize(),
                pointer.GetPosition()
            );
            break;

        case INVENTORY:
            std::cout << menus.GetInventoryMenuTitle() << "\n\n";
            drawer.DrawMenu(
                menus.GetInventoryMenu(),
                menus.GetInventoryMenuSize(),
                pointer.GetPosition()
            );
            break;

        case SHOP:
            std::cout << menus.GetShopMenuTitle() << "\n\n";
            drawer.DrawMenu(
                menus.GetShopMenu(),
                menus.GetShopMenuSize(),
                pointer.GetPosition()
            );
            break;
        }

        int key = _getch();

        switch (key)
        {
        case 224:
            key = _getch();

            switch (key)
            {
            case 72:
                pointer.MoveUp();
                break;

            case 80:
                switch (currentMenu)
                {
                case MAIN:
                    pointer.MoveDown(menus.GetMainMenuSize());
                    break;
                case INVENTORY:
                    pointer.MoveDown(menus.GetInventoryMenuSize());
                    break;
                case SHOP:
                    pointer.MoveDown(menus.GetShopMenuSize());
                    break;
                }
                break;
            }
            break;

        case 13:
            switch (currentMenu)
            {
            case MAIN:
                switch (pointer.GetPosition())
                {
                case 0:
                    currentMenu = INVENTORY;
                    pointer.Reset();
                    break;

                case 1:
                    currentMenu = SHOP;
                    pointer.Reset();
                    break;

                case 2:
                    running = false;
                    break;
                }
                break;

            case INVENTORY:
                if (pointer.GetPosition() == menus.GetInventoryMenuSize() - 1)
                {
                    currentMenu = MAIN;
                    pointer.Reset();
                }
                break;

            case SHOP:
                if (pointer.GetPosition() == menus.GetShopMenuSize() - 1)
                {
                    currentMenu = MAIN;
                    pointer.Reset();
                }
                break;
            }
            break;
        }
    }

    return 0;
}