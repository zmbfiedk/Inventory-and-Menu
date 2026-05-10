#pragma once

class Pointer
{
private:
    int position;

public:
    Pointer();

    void MoveUp();
    void MoveDown(int max);
    void Reset();
    int GetPosition();
};