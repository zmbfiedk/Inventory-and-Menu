#include "Cursor.h"

Cursor::Cursor()
{
    position = 0;
}

void Cursor::MoveUp()
{
    if (position > 0)
        position--;
}

void Cursor::MoveDown(int max)
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
    if (position >= max)
        position = max - 1;
}

int Cursor::GetPosition() const
{
    return position;
}