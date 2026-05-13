#include "Item.h"

Item::Item()
{
    name = "";
}

Item::Item(const std::string& itemName)
{
    name = itemName;
}

void Item::SetName(const std::string& itemName)
{
    name = itemName;
}

std::string Item::GetName()
{
    return name;
}