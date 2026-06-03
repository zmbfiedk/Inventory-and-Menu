#include "Cursor.h"

Cursor::Cursor() : position(0) {}

void Cursor::Up()
{
    if (position > 0)
        position--;
}

void Cursor::Down(int max)
{
    if (position < max - 1)
        position++;
}

void Cursor::Reset()
{
    position = 0;
}

void Cursor::Clamp(int max)
{
    if (max <= 0)
        position = 0;
    else if (position >= max)
        position = max - 1;
    else if (position < 0)
        position = 0;
}

int Cursor::GetPosition() const
{
    return position;
}