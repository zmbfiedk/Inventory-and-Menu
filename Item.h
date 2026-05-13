#pragma once
#include <string>

class Item
{
private:
    std::string name;

public:
    Item();
    Item(const std::string& itemName);

    void SetName(const std::string& itemName);
    std::string GetName();
};