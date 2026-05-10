#include "Pointer.h"

Pointer::Pointer()
{
    position = 0;
}

void Pointer::MoveUp()
{
    if (position > 0)
        position--;
}

void Pointer::MoveDown(int max)
{
    if (position < max - 1)
        position++;
}

void Pointer::Reset()
{
    position = 0;
}

int Pointer::GetPosition()
{
    return position;
}