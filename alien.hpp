#pragma once
#include <raylib.h>

class Alien 
{
    public:
    Alien(int type,Vector2 position);
    void Update(int direction);
    void Draw();
    int GetType();
    static void UnloadImages();
    static Texture2D alieanImages[3];
    Vector2 position;
    int type;
    private:
};
