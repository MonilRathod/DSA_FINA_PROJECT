#include "alien.hpp"

Alien::Alien(int type, Vector2 position)
{
    this -> type = type;
    this -> position = position;

    switch(type)
    {
        case 0:
            image = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/alien_1.png");
            break;
        case 1:
            image = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/alien_2.png");
            break;
        case 2:
            image = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/alien_3.png");
            break;
        default:
            image = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/alien_1.png");
            break;
    }

}

void Alien::Draw()
{
    DrawTextureV(image, position, WHITE);
}

int Alien::GetType()
{
    return type;
}