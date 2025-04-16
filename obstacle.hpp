#pragma once
#include"block.hpp"
#include<vector>

class Obstacle
{
    public:
    Obstacle(Vector2 position);
    void Draw();
    std::vector<Block> blocks;
    static std::vector<std::vector<int>> grid;
    Vector2 position;


    private:
    
};