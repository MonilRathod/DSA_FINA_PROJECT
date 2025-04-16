#pragma once
#include <raylib.h>



class MysteryShip 
{
    public:
    MysteryShip();
    ~MysteryShip();
    void Draw();
    void Update();
    void Spawn();
    bool alive;
    Rectangle GetRect();
    
    private:
    Texture2D image;
    Vector2 position;
    int speed;
};