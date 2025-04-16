#include <raylib.h>

int main(){
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "space invaders");
    SetTargetFPS(60);

    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(GRAY);
        EndDrawing();
    }

    CloseWindow();
}
