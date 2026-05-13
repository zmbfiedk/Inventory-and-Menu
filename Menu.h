#pragma once
#include <string>
#include <vector>

class Menu
{
private:
    std::string title;
    std::vector<std::string> options;

public:
    Menu();
    Menu(const std::string& menuTitle, const std::vector<std::string>& menuOptions);

    void SetTitle(const std::string& menuTitle);
    void SetOptions(const std::vector<std::string>& menuOptions);

    std::string GetTitle();
    std::string* GetOptions();
    int GetSize();
};