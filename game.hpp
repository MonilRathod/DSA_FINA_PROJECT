#pragma once
#include"spaceship.hpp"
#include"obstacle.hpp"
#include "alien.hpp"
#include"mysteryship.hpp"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    void TogglePause();
    bool run;
    int lives;
    int score;
    int HighScore;
    Music music;
    bool paused = false;

private:
    void DeletInactiveLasers();
    std::vector<Obstacle> CreatObstacles();
    std::vector<Alien> CreatAliens();
    void MoveAliens();
    void MoveDownAliens(int distance);
    void AlienShootLasers();
    void CheckForCollision();
    void GameOver();
    void Reset();
    void InitGame();
    void CheckForHIghScore();
    void HighScoreToFile(int HighScore);
    void ResetHighScore();
    int LoadHighScoreFromFile();
    Spaceship spaceship;
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    int alienDirection;
    std::vector<Laser>alienLasers;
    constexpr static float AlianLaserShootInterval = 0.35;
    float TimeLastAlienFired;
    MysteryShip mysteryShip;
    float mysteryShipSpawnintrval;
    float timeLastspawn;
    Sound explosionSound;
};
