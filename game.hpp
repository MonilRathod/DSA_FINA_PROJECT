#pragma once
#include"spaceship.hpp"
#include"obstacle.hpp"
#include "alien.hpp"

class Game
{
    public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    private:
    void DeletInactiveLasers();
    std::vector<Obstacle> CreatObstacles();
    std::vector<Alien> CreatAliens();
    Spaceship spaceship;
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    

};