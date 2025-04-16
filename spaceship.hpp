#pragma once
#include <raylib.h>
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
    
    private:
    Texture2D image;
    Vector2 position;


};