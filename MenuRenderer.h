#pragma once
#include <vector>
#include <string>
#include "Item.h"

class MenuRenderer
{
public:
    void DrawMainMenu(const std::string* options, int size, int cursor, int gold) const;
    void DrawItemMenu(const std::string& title, const std::vector<Item>& items, int cursor, int gold,
        bool buying, int backIndex, int totalValue) const;
};