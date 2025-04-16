#include <raylib.h>
#include "game.hpp"
#include <string>

std::string FormatWithLeadingZeros(int number, int width)
{
    std::string numberText = std::to_string(number);
    int leadingzeros = width - numberText.length();
    return numberText = std::string(leadingzeros, '0') + numberText;

}



int main()
{
    Color yellow = { 243, 216, 63, 255 };
    Color black = { 0, 0, 0, 255 };
    int windowWidth = 750;
    int windowHeight = 700;
    int offset = 50;

    InitWindow(windowWidth + offset, windowHeight + 2 * offset, "space invaders");
    Font font = LoadFontEx("C:/Users/M416/Desktop/DSA_FINA_PROJECT/font/monogram.ttf", 64, 0, 0);
    Texture2D Spaceshipimage = LoadTexture("C:/Users/M416/Desktop/DSA_FINA_PROJECT/graphics/spaceship.png");
    SetTargetFPS(60);

    Game game;
    

    while(WindowShouldClose() == false)
    {

        game.HandleInput();
        game.Update();

        BeginDrawing();
        ClearBackground(black);
        DrawRectangleRoundedLinesEx({10, 10, 780, 780}, 0.18f, 20,2, yellow);
        DrawLineEx({25,730}, {770,730},3, yellow);

        if(game.run)
        {
            DrawTextEx(font, "LEVEL 01", {570, 740 }, 34, 2, yellow);
        }
        else
        {
            DrawTextEx(font, "GAMEOVER", {570, 740 }, 34, 2, yellow);

        }
        float x=50.0;

        for(int i =0; i < game.lives; i++)
        {
            DrawTextureV(Spaceshipimage, {x,745}, WHITE);
            x +=50;
        }

        DrawTextEx(font, "SCORE", {50, 15 }, 34, 2, yellow);
        std::string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 60 }, 34, 2, yellow);

        DrawTextEx(font, "HIGH-SCORE", {570, 15 }, 34, 2, yellow);
        std::string highScoreText = FormatWithLeadingZeros(game.HighScore, 5);
        DrawTextEx(font, highScoreText.c_str(), {655, 40 }, 34, 2, yellow);

        

        game.Draw();


        


        EndDrawing();
    }

    CloseWindow();
}
