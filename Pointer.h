#pragma once

class Pointer
{
private:
    int position;

public:
    Pointer();

    void MoveUp();
    void MoveDown(int max);
    int GetPosition();
};