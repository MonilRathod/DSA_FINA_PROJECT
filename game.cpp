#include "game.hpp"
#include <iostream>

Game::Game()
{
    obstacles = CreatObstacles();
    aliens = CreatAliens();

}

Game::~Game()
{}

void Game::Update()
{
    for(auto& laser : spaceship.lasers)
    {
        laser.Update();
    }

    DeletInactiveLasers();
    std::cout<<"vector size"<<spaceship.lasers.size()<<std::endl;
}

void Game::Draw()
{
    spaceship.Draw();

    for(auto& laser : spaceship.lasers)
    {
        laser.Draw();
    }

    for(auto& obstacle : obstacles)
    {
        obstacle.Draw();
    }

    for(auto& alien : aliens)
    {
        alien.Draw();
    }

}

void Game::HandleInput()
{
    if (IsKeyDown(KEY_LEFT)) spaceship.MoveLeft();
    if (IsKeyDown(KEY_RIGHT)) spaceship.MoveRight();
    if (IsKeyDown(KEY_SPACE)) spaceship.FireLaaser();   
}

void Game::DeletInactiveLasers()
{
    for(auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();)
    {
        if(it->active == false)
        {
            it = spaceship.lasers.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
std::vector<Obstacle> Game::CreatObstacles()
{
    int ObstacleWidth = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() - (4 * ObstacleWidth)) / 5;

    for(int i = 0; i < 4; i++)
    {
        float offsetX = (i+1)* gap + i * ObstacleWidth;
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100)}));


    }
    return obstacles;
}

std::vector<Alien> Game::CreatAliens()
{
   std::vector<Alien> aliens;
   for(int row = 0; row < 5; row++)
   {
       for(int colum = 0; colum < 11; colum++)
       {
           int alienType;
           if(row == 0) alienType = 3;
           else if(row == 1 || row == 2) alienType = 2;
           else alienType = 1;
           

           float x = 75+colum*55;
           float y = 110+row*55;
           aliens.push_back(Alien(alienType, {x,y}));
       }
   }
   return aliens;
}
