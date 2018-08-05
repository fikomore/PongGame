//
//  player.hpp
//  PongGame
//
//  Created by Fikrim Kabashi on 16.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include "grahpics.hpp"

class Graphics;

class Player{
private:
    SDL_Texture* texture;
    SDL_Rect sourceRect;
    int posX;
    int posY;
    int width;
    int height;
    
public:
    Player();
    Player(Graphics &graphics,const std::string &filePath,int sourceX, int sourceY, int width, int height, int posX, int posY);
    ~Player();
    void draw(Graphics &graphics);
    void moveLeft();
    void moveRight();
    
    int getPositionX();
    int getPositionY();
    int getWidth();
    int getHeight();
};

#endif /* player_hpp */
