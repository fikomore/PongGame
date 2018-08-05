//
//  player.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 16.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "player.hpp"

Player::Player(){};
Player::Player(Graphics graphics,const std::string &filePath,int sourceX, int sourceY, int width, int height, int posX, int posY){
    this->sourceRect.x = sourceX;
    this->sourceRect.y = sourceY;
    this->sourceRect.w = width;
    this->sourceRect.h = height;
    this->posX = posX;
    this->posY = posY;
    texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if(this->texture == NULL){
        printf("\nError: unable to load image\n");
    }
}

Player::~Player(){};

void Player::draw(Graphics &graphics){
    SDL_Rect destinationRectangle;
    destinationRectangle.x = this->posX;
    destinationRectangle.y = this->posY;
    destinationRectangle.w = this->sourceRect.w;
    destinationRectangle.h = this->sourceRect.h;
    graphics.blitSurface(texture, &this->sourceRect, &destinationRectangle);
}
