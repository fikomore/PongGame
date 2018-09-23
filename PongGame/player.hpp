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
    SDL_Texture* texture_;
    SDL_Rect source_rectangle_;
    int start_pos_x_;
    int start_pos_y_;
    int pos_x_;
    int pos_y_;
    int width_;
    int height_;
    
public:
    Player();
    Player(Graphics &graphics,const std::string &filePath,int sourceX, int sourceY, int width, int height, int posX, int posY);
    ~Player();
    void Draw(Graphics &graphics);
    void MoveLeft();
    void MoveRight();
    void Restart();
    
    int GetPositionX();
    int GetPositionY();
    int GetWidth();
    int GetHeight();
};

#endif /* player_hpp */
