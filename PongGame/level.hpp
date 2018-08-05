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

#include <SDL2/SDL.h>
#include "grahpics.hpp"


class Level{
private:
    SDL_Texture* texture;
    int width;
    int height;
    int map[8][10]={
        {0,1,1,1,1,1,1,1,1,2},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {6,8,8,8,8,8,8,8,8,7},
        {3,4,4,4,4,4,4,4,4,5}
    };
    
public:
    Level();
    Level(Graphics &graphics, const std::string &filePath, int width, int height);
    ~Level();
    
    void draw(Graphics &graphics);
};
#endif /* level_hpp */
