#include "MenuRenderer.h"
#include <iostream>
#include <iomanip>

static void PrintSidePanel(const std::vector<std::string>& lines)
{
    std::cout << "\n";
    for (const std::string& line : lines)
        std::cout << std::setw(42) << std::left << " " << line << "\n";
}

void MenuRenderer::DrawMainMenu(
    const std::string menu[],
    int size,
    int cursor,
    int gold
)
{
    std::vector<std::string> controls =
    {
        "Controls",
        "Arrow Up/Down : Move",
        "Enter         : Select",
        "Backspace     : Back",
        "",
        "Gold is shown",
        "in the menus"
    };

    std::cout << "MAIN MENU\n\n";

    for (int i = 0; i < size; i++)
    {
        std::cout << (i == cursor ? "-> " : "   ");
        std::cout << menu[i] << "\n";
    }

    std::cout << "\nGold: " << gold << "\n";

    PrintSidePanel(controls);
}

void MenuRenderer::DrawItemMenu(
    const std::string& title,
    const std::vector<Item>& items,
    int cursor,
    bool buying,
    int gold,
    const std::string& statusMessage
)
{
    std::vector<std::string> controls =
    {
        "Controls",
        "Arrow Up/Down : Move",
        buying ? "Enter         : Buy" : "Enter         : Sell / Pick up",
        "Backspace     : Back",
        "",
        "Hover items to",
        "see details"
    };

    std::cout << title << "\n\n";
    std::cout << "Gold: " << gold << "\n";

    if (!statusMessage.empty())
        std::cout << statusMessage << "\n";

    std::cout << "\n";

    for (int i = 0; i < (int)items.size(); i++)
    {
        std::cout << (i == cursor ? "-> " : "   ");
        std::cout << items[i].GetName();

        if (buying)
            std::cout << " [Buy: " << std::max(1, items[i].GetBaseValue() + 10) << "]";
        else
            std::cout << " [Sell: " << std::max(1, items[i].GetBaseValue() / 2) << "]";

        std::cout << "\n";
    }

    std::cout << (cursor == (int)items.size() ? "-> " : "   ") << "Back\n\n";

    if (cursor < (int)items.size() && !items.empty())
    {
        const Item& item = items[cursor];
        std::cout << item.GetName() << " (" << item.GetTypeText() << ")\n";
        std::cout << item.GetStatsText() << "\n";
        std::cout << item.GetDescription() << "\n";
    }
    else
    {
        std::cout << "Return to the main menu.\n";
    }

    PrintSidePanel(controls);
}