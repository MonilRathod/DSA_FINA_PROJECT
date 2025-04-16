#include "spaceship.hpp"

Spaceship::Spaceship()
{
    image = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/spaceship.png");
    position.x = (GetScreenWidth()-image.width) / 2;
    position.y = (GetScreenHeight()-image.height);
    LastFireTime = 0;
}

Spaceship::~Spaceship()
{
    UnloadTexture(image);
}

void Spaceship::Draw()
{
    DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft()
{
 position.x -= 7;
    if (position.x < 0) position.x = 0;
}

void Spaceship::MoveRight()
{
 position.x += 7;
    if (position.x > GetScreenWidth() - image.width) position.x = GetScreenWidth() - image.width;
}

void Spaceship::FireLaaser()
{
    if(GetTime() - LastFireTime >= 0.35)
    {
    lasers.push_back(Laser({position.x + image.width / 2 - 2, position.y},-6));
    LastFireTime = GetTime();
    }
}
