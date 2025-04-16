#include "mysteryship.hpp"

MysteryShip::MysteryShip()
{
    image = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/mystery.png");
    alive = true;
}

MysteryShip::~MysteryShip()
{
    UnloadTexture(image);
}

void MysteryShip::Spawn()
{
    position.y = 90;
    int side = GetRandomValue(0, 1);

    if(side == 0)
    {
        position.x = 25;
        speed = 3;
    }
    else
    {
        position.x = GetScreenWidth() - image.width-25;
        speed = -3;
    }
    alive = true;
}

void MysteryShip::Update()
{
    if(alive)
    {
        position.x += speed;
        if(position.x < 25  || position.x > GetScreenWidth() - image.width + 25)
        {
            alive = false;
        }
    }
}

void MysteryShip::Draw()
{
    if(alive)
    {
        DrawTextureV(image, position, WHITE);
    }
}

Rectangle MysteryShip::GetRect()
{
    if(alive)
    {
        return {position.x, position.y, float(image.width), float(image.height)};
    }
    else
    {
        return {position.x, position.y, 0, 0};
    }
}