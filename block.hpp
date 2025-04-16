#pragma once
#include <raylib.h>

class Block 
{
    public:
    Block(Vector2 position);
    void Update();
    void Draw();
    bool active;
    Rectangle GetRect();
    private:
    Vector2 position;
};