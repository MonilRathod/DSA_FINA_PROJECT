#pragma once
#include <raylib.h>
#include"laser.hpp"
#include <vector>


class Spaceship 
{

    public:
    Spaceship();
    ~Spaceship();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void FireLaaser();
    Rectangle GetRect();
    std::vector<Laser> lasers;
    
    private:
    Texture2D image;
    Vector2 position;
    double LastFireTime;

};