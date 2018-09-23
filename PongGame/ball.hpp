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
    SDL_Texture* texture_;
    SDL_Rect source_rectangle_;
    SDL_Rect destination_rectangle_;
    ballDirection direction_;
    
    int start_pos_x_;
    int start_pos_y_;
    int pos_x_;
    int pos_y_;
    int width_;
    int height_;
public:
    Ball();
    Ball(Graphics &graphics,const std::string &filePath, int sourceX, int sourceY, int width, int height, int posX, int posY);
    ~Ball();
    
    int GetPositionX();
    int GetPositionY();
    int GetHeight();
    int GetWidth();
    SDL_Rect GetRectangle();
    
    ballDirection GetDirection();
    
    void Draw(Graphics &graphics);
    void Move();
    void SetDirection(ballDirection direction);
    void Restart();
};

#endif /* ball_hpp */
