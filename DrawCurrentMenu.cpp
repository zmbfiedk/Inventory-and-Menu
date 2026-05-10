#include "DrawCurrentMenu.h"
#include <iostream>

void DrawCurrentMenu::DrawMenu(std::string menu[], int size, int pointerPos)
{
    for (int i = 0; i < size; i++)
    {
        if (i == pointerPos)
            std::cout << "-> ";
        else
            std::cout << "   ";

        std::cout << menu[i] << "\n";
    }
}