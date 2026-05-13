#include "Menu.h"

Menu::Menu()
{
    title = "";
}

Menu::Menu(const std::string& menuTitle, const std::vector<std::string>& menuOptions)
{
    title = menuTitle;
    options = menuOptions;
}

void Menu::SetTitle(const std::string& menuTitle)
{
    title = menuTitle;
}

void Menu::SetOptions(const std::vector<std::string>& menuOptions)
{
    options = menuOptions;
}

std::string Menu::GetTitle()
{
    return title;
}

std::string* Menu::GetOptions()
{
    if (options.empty())
        return nullptr;

    return options.data();
}

int Menu::GetSize()
{
    return static_cast<int>(options.size());
}