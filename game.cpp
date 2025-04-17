#include "game.hpp"
#include <iostream>
#include <fstream>

Game::Game()
{
    music = LoadMusicStream("C:/Users/M416/Desktop/DSA_FINA_PROJECT/sound/music.ogg");
    explosionSound = LoadSound("C:/Users/M416/Desktop/DSA_FINA_PROJECT/sound/explosion.ogg");
    PlayMusicStream(music);
    InitGame();
}

Game::~Game()
{
    Alien::UnloadImages();
    UnloadMusicStream(music);
    UnloadSound(explosionSound);
}

void Game::Update()
{
    if(paused)
    {
        return;
    }
    if(run)
    {

        double currentTime = GetTime();
        if(currentTime - timeLastspawn >= mysteryShipSpawnintrval)
        {
            mysteryShip.Spawn();
            timeLastspawn = GetTime();
            mysteryShipSpawnintrval = GetRandomValue(10,20);
        }
    
    
        for(auto& laser : spaceship.lasers)
        {
            laser.Update();
        }
    
        MoveAliens();
        AlienShootLasers();
        for(auto& laser : alienLasers)
        {
            laser.Update();
        }
    
        DeletInactiveLasers();
        //std::cout<<"vector size"<<spaceship.lasers.size()<<std::endl;
    
        mysteryShip.Update();
    
        CheckForCollision();
    } 
    else
    {
        if(IsKeyPressed(KEY_ENTER))
        {
            Reset();
            InitGame();
        }
        
    }   
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

    for(auto& laser : alienLasers)
    {
        laser.Draw();
    }

    mysteryShip.Draw();

}

void Game::HandleInput()
{
    if (IsKeyPressed(KEY_P)) TogglePause();
    if(!paused && run)
    {
        if (IsKeyDown(KEY_LEFT)) spaceship.MoveLeft();
        if (IsKeyDown(KEY_RIGHT)) spaceship.MoveRight();
        if (IsKeyDown(KEY_SPACE)) spaceship.FireLaaser(); 
        if (IsKeyPressed(KEY_R))  ResetHighScore();
    
    }  
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

    for(auto it = alienLasers.begin(); it != alienLasers.end();)
    {
        if(it->active == false)
        {
            it = alienLasers.erase(it);
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
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 200)}));


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
void Game::MoveAliens()
{
    for(auto& alien : aliens)
    {
        if(alien.position.x + alien.alieanImages[alien.type - 1].width > GetScreenWidth() - 25)
        {
            alienDirection = -1;
            MoveDownAliens(4);
        }
        if(alien.position.x < 25)
        {
            alienDirection = 1;
            MoveDownAliens(4);
        }
        alien.Update(alienDirection);
    }
}

void Game::MoveDownAliens(int distance)
{
    for(auto& alien : aliens)
    {
        alien.position.y += distance;
    }
}

void Game::AlienShootLasers()
{
    double currentTime = GetTime();
    if(currentTime - TimeLastAlienFired >= AlianLaserShootInterval && !aliens.empty())
    {
        
    
    int randomIndex = GetRandomValue(0, aliens.size() - 1);
    Alien& alien = aliens[randomIndex];
    alienLasers.push_back(Laser({alien.position.x + alien.alieanImages[alien.type - 1].width / 2,
                                 alien.position.y + alien.alieanImages[alien.type - 1].height}, 6));

    TimeLastAlienFired = GetTime();                             
    }
}

void Game::CheckForCollision()
{

    //space ship laser
    for(auto& laser : spaceship.lasers)
    {
        auto it = aliens.begin();
        while(it != aliens.end())
        {
            if(CheckCollisionRecs(it->GetRect(), laser.GetRect()))
            {
                PlaySound(explosionSound);
                if(it->type==1)
                {
                    score += 100;
                }
                else if(it->type==2)
                {
                    score += 200;
                }
                else if(it->type==3)
                {
                    score += 300;
                }
                CheckForHIghScore();
               
                it = aliens.erase(it);
                laser.active = false;
            }
            else
            {
                ++it;

            }
            
        }
    
        for(auto& obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while(it != obstacle.blocks.end())
            {
                if(CheckCollisionRecs(it->GetRect(), laser.GetRect()))
                {
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else
                {
                    ++it;   
                }
            }    
            
        }

        if(CheckCollisionRecs(mysteryShip.GetRect(), laser.GetRect()))
        {
            PlaySound(explosionSound);
            laser.active = false;
            mysteryShip.alive = false;
            score += 500;
            CheckForHIghScore();
        }
    }
    for(auto& laser : alienLasers)
    {
        if(CheckCollisionRecs(laser.GetRect(), spaceship.GetRect()))
        {
            laser.active = false;
            lives--;
            if(lives <= 0)
            {
                GameOver();
            }
        }
        
    
        for(auto& obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while(it != obstacle.blocks.end())
            {
                if(CheckCollisionRecs(it->GetRect(), laser.GetRect()))
                {
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else
                {
                    ++it;   
                }
            }          
        }
    }  
    
    for(auto& alien : aliens)
    {
        for(auto& obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while(it != obstacle.blocks.end())
            {
                if(CheckCollisionRecs(it->GetRect(), alien.GetRect()))
                {
                    it = obstacle.blocks.erase(it);
                }
                else
                {
                    ++it;   
                }          
            }
        } 
        if(CheckCollisionRecs(alien.GetRect(), spaceship.GetRect()))
        {
            GameOver();
        }
    }  
}


void Game::GameOver()
{
    run = false;
}

void Game::InitGame()
{
    obstacles = CreatObstacles();
    aliens = CreatAliens();
    alienDirection = 1;
    TimeLastAlienFired = 0.0;
    timeLastspawn = 0.0;
    mysteryShipSpawnintrval = GetRandomValue(10,20);
    lives = 3;
    run = true;
    score = 0;
    HighScore = LoadHighScoreFromFile();
}

void Game::CheckForHIghScore()
{

    if(score > HighScore)
    {
        HighScore = score;
        HighScoreToFile(HighScore);
    }
}

void Game::HighScoreToFile(int HighScore)
{
    std::ofstream HighScorefile("highscore.txt");
    if(HighScorefile.is_open())
    {
        HighScorefile << HighScore;
        HighScorefile.close();
    }
    else
    {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

int Game::LoadHighScoreFromFile()
{
    int LodedHighScore = 0;
    std::ifstream HighScorefile("highscore.txt");
    if(HighScorefile.is_open())
    {
        HighScorefile >> LodedHighScore;
        HighScorefile.close();
    }
    else
    {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
    return LodedHighScore;
}

void Game::Reset()
{
    spaceship.Reset();
    aliens.clear();
    alienLasers.clear();
    obstacles.clear();
}

void Game::ResetHighScore()
{
    HighScore = 0;
    HighScoreToFile(HighScore);
}

void Game::TogglePause() {
    paused = !paused;
}
