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
        if(position.y < 0 || position.y > GetScreenHeight())
        {
            active = false;
            std::cout<<"Laser Inactive"<<std::endl;

        }
    }
    position.y += speed;
}