//
//  level.hpp
//  PongGame
//
//  Created by Fikrim Kabashi on 30.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef level_hpp
#define level_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include "grahpics.hpp"


class Level{
private:
    SDL_Texture* texture_;
    SDL_Texture* block_texture_;
    int width_;
    int height_;
    int map_[8][10]={
        {0,1,1,1,1,1,1,1,1,2},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {3,4,4,4,4,4,4,4,4,5}
    };
    
    std::vector<std::vector<SDL_Rect>> start_block_;
    std::vector<std::vector<SDL_Rect>> block_;
//    SDL_Rect block[12][5];
    
public:
    Level();
    Level(Graphics &graphics, const std::string &filePath, int width, int height);
    ~Level();
    
    std::vector<std::vector<SDL_Rect>> &GetBlockVector();
    void Restart();
    void LoadBlock(Graphics &graphics, const std::string &filePath);
    void Draw(Graphics &graphics);
};
#endif /* level_hpp */
