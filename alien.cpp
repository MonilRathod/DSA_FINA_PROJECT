#include "alien.hpp"

Texture2D Alien::alieanImages[3]={};

Alien::Alien(int type, Vector2 position)
{
    this -> type = type;
    this -> position = position;

    if(alieanImages[type-1].id == 0)
    {


    switch(type)
    {
        case 1:
            alieanImages[0] = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/alien_1.png");
            break;
        case 2:
            alieanImages[1] = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/alien_2.png");
            break;
        case 3:
            alieanImages[2] = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/alien_3.png");
            break;
        default:
            alieanImages[0] = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/alien_1.png");
            break;
    }
    }

}

void Alien::Draw()
{
    DrawTextureV(alieanImages[type-1], position, WHITE);
}

int Alien::GetType()
{
    return type;
}

void Alien::UnloadImages()
{
    for(int i = 0; i < 4; i++)
    {
        UnloadTexture(alieanImages[i]);
    }
}

void Alien::Update(int direction)
{
    position.x += direction;    
}

Rectangle Alien::GetRect()
{
    return {position.x, position.y, float(alieanImages[type-1].width), float(alieanImages[type-1].height)};
}
