#pragma once

class Cursor
{
private:
    int position;

public:
    Cursor();

    void Up();
    void Down(int max);
    void Reset();
    void Clamp(int max);

    int GetPosition() const;
};