//
//  player.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 16.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//


#include "player.hpp"
#include "globals.h"

Player::Player(){};
Player::Player(Graphics &graphics,const std::string &filePath,int sourceX, int sourceY, int width, int height, int posX, int posY){
    source_rectangle_.x = sourceX;
    source_rectangle_.y = sourceY;
    source_rectangle_.w = width;
    source_rectangle_.h = height;
    pos_x_ = start_pos_x_ = posX;
    pos_y_ = start_pos_y_ = posY;
    width_ = width;
    height_ = height;
    texture_ = SDL_CreateTextureFromSurface(graphics.GetRenderer(), graphics.LoadImage(filePath));
    if(texture_ == nullptr){
        printf("\nError: unable to load image\n");
    }
}

Player::~Player(){};

void Player::Draw(Graphics &graphics){
    SDL_Rect destinationRectangle;
    destinationRectangle.x = pos_x_;
    destinationRectangle.y = pos_y_;
    destinationRectangle.w = source_rectangle_.w;
    destinationRectangle.h = source_rectangle_.h;
    graphics.BlitSurface(texture_, &source_rectangle_, &destinationRectangle);
}

void Player::MoveLeft(){
    if(pos_x_ > globals::kBackgroungBlockSize/2) //Spravit to do rozumnej formy
        pos_x_-=3;
}

void Player::MoveRight(){
    if(pos_x_ < globals::kScreenWidth-globals::kBackgroungBlockSize/2-width_) //Spravit to do rozumnej formy
        pos_x_+=3;
}

int Player::GetPositionX(){
    return pos_x_;
}

int Player::GetPositionY(){
    return pos_y_;
}

int Player::GetWidth(){
    return width_;
}

int Player::GetHeight(){
    return height_;
}

void Player::Restart(){
    this->pos_x_ = start_pos_x_;
    this->pos_y_ = start_pos_y_;
}
