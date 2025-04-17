#include "spaceship.hpp"

Spaceship::Spaceship()
{
    image = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/spaceship.png");
    position.x = (GetScreenWidth()-image.width) / 2;
    position.y = (GetScreenHeight()-image.height) - 100;
    LastFireTime = 0;
    lasersound = LoadSound("C:/Users/M416/Desktop/DSA_FINA_PROJECT/sound/laser.ogg");
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
    if (position.x < 25) position.x = 25;
}

void Spaceship::MoveRight()
{
 position.x += 7;
    if (position.x > GetScreenWidth() - image.width -25) position.x = GetScreenWidth() - image.width -25;
}

void Spaceship::FireLaaser()
{
    if(GetTime() - LastFireTime >= 0.35)
    {
    lasers.push_back(Laser({position.x + image.width / 2 - 2, position.y},-6));
    LastFireTime = GetTime();
    PlaySound(lasersound);
    }
}

Rectangle Spaceship::GetRect()
{
    return{position.x, position.y, float(image.width), float(image.height)};
}

void Spaceship::Reset()
{
    lasers.clear();
    position.x = (GetScreenWidth()-image.width) / 2;
    position.y = (GetScreenHeight()-image.height)-100;
}
