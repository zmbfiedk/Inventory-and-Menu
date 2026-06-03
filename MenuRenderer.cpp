#include "MenuRenderer.h"
#include <iostream>

void MenuRenderer::DrawMainMenu(const std::string* options, int size, int cursor, int gold) const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << (i == cursor ? "-> " : "   ") << options[i] << "\n";
    }

    std::cout << "\nGold: " << gold << "\n";
}

void MenuRenderer::DrawItemMenu(const std::string& title, const std::vector<Item>& items, int cursor, int gold,
    bool buying, int backIndex, int totalValue) const
{
    std::cout << title << "\n\n";
    std::cout << "Gold: " << gold << "\n";
    std::cout << "Total item sell value: " << totalValue << "\n\n";

    for (int i = 0; i < (int)items.size(); i++)
    {
        std::cout << (i == cursor ? "-> " : "   ");
        std::cout << items[i].GetName();

        if (buying)
            std::cout << "  [Buy: " << std::max(1, (items[i].GetBaseValue() * 3) / 2) << "]";
        else
            std::cout << "  [Sell: " << std::max(1, items[i].GetBaseValue() / 2) << "]";

        std::cout << "\n";
    }

    std::cout << (cursor == backIndex ? "-> " : "   ") << "Back\n\n";

    if (cursor < (int)items.size())
    {
        const Item& item = items[cursor];
        std::cout << item.GetName() << " (" << item.GetTypeName() << ")\n";
        std::cout << item.GetStatsText() << "\n";
        std::cout << item.GetDescription() << "\n";
    }
    else
    {
        std::cout << "Return to the main menu.\n";
    }
}