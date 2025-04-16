#include <raylib.h>
#include "game.hpp"

int main(){
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "space invaders");
    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
