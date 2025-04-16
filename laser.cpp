#include "laser.hpp"
#include<iostream>

Laser::Laser(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
    active = true;
}

void Laser::Draw()
{
    if(active)
    DrawRectangle(position.x, position.y, 4, 15,{245,216,63,255});
}

void Laser::Update()
{
    if(active){
        if(position.y < 25 || position.y > GetScreenHeight()-100)
        {
            active = false;

        }
    }
    position.y += speed;
}
Rectangle Laser::GetRect()
{
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = 4;
    rect.height = 15;
    return rect;
}