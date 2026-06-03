#pragma once

class Cursor
{
private:
    int position;

public:
    Cursor();

    void MoveUp();

    void MoveDown(int max);

    void Reset();

    void Clamp(int max);

    int GetPosition() const;
};