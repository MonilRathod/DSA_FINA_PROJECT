#include "spaceship.hpp"

Spaceship::Spaceship()
{
    image = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/spaceship.png");
    position.x = (GetScreenWidth()-image.width) / 2;
    position.y = (GetScreenHeight()-image.height);
}

Spaceship::~Spaceship()
{
    UnloadTexture(image);
}

void Spaceship::Draw()
{
    DrawTextureV(image, position, WHITE);
}