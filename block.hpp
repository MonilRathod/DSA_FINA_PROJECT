#pragma once
#include <raylib.h>

class Block 
{
    public:
    Block(Vector2 position);
    void Update();
    void Draw();
    bool active;
    private:
    Vector2 position;
};