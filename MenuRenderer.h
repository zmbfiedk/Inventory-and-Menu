#pragma once
#include <vector>
#include <string>
#include "Item.h"

class MenuRenderer
{
public:
    void DrawMainMenu(
        const std::string menu[],
        int size,
        int cursor,
        int gold
    );

    void DrawItemMenu(
        const std::string& title,
        const std::vector<Item>& items,
        int cursor,
        bool buying,
        int gold,
        const std::string& statusMessage
    );
};