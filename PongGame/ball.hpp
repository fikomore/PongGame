//
//  ball.hpp
//  PongGame
//
//  Created by Fikrim Kabashi on 17.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef ball_hpp
#define ball_hpp

#include <SDL2/SDL.h>
#include <string>
#include "grahpics.hpp"
#include "globals.h"

class Ball{
private:
    SDL_Texture* texture;
    SDL_Rect sourceRectangle;
    
    ballDirection direction;
    
    int posX;
    int posY;
    int width;
    int height;
public:
    Ball();
    Ball(Graphics &graphics,const std::string &filePath, int sourceX, int sourceY, int width, int height, int posX, int posY);
    ~Ball();
    
    int getPositionX();
    int getPositionY();
    int getHeight();
    int getWidth();
    
    ballDirection getDirection();
    
    void draw(Graphics &graphics);
    void move();
    void setDirection(ballDirection direction);
};

#endif /* ball_hpp */
