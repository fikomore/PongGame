//
//  ball.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 17.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "ball.hpp"
#include <iostream>

Ball::Ball(){};

Ball::Ball(Graphics &graphics,const std::string &filePath, int sourceX, int sourceY, int width, int height, int posX, int posY)
{
    source_rectangle_.x = sourceX;
    source_rectangle_.y = sourceY;
    source_rectangle_.w = width;
    source_rectangle_.h = height;
    
    direction_ = STOP;
    
    pos_x_ = start_pos_x_ = posX;
    pos_y_ = start_pos_y_ = posY;
    width_ = width;
    height_ = height;
    
    texture_ = SDL_CreateTextureFromSurface(graphics.GetRenderer(), graphics.LoadImage(filePath));
    if(texture_ == nullptr){
        printf("\nError: unable to load BALL image.\n");
    }
}

Ball::~Ball(){};

void Ball::Draw(Graphics &graphics) {
    destination_rectangle_.x = pos_x_;
    destination_rectangle_.y = pos_y_;
    destination_rectangle_.w = source_rectangle_.w;
    destination_rectangle_.h = source_rectangle_.h;
//    std::cout<<destinationRectangle.x<<destinationRectangle.y<<destinationRectangle.w<<destinationRectangle.h<<std::endl;
    graphics.BlitSurface(texture_, &source_rectangle_, &destination_rectangle_);
}

void Ball::Move(){
    switch (direction_) {
        case STOP:
            break;
        case UP:
            pos_y_--;
            break;
        case DOWN:
            pos_y_++;
            break;
        case LEFT_UP:
            pos_x_--;
            pos_y_--;
            break;
        case RIGHT_UP:
            pos_x_++;
            pos_y_--;
            break;
        case LEFT_DOWN:
            pos_x_--;
            pos_y_++;
            break;
        case RIGHT_DOWN:
            pos_x_++;
            pos_y_++;
            break;
        default:
            break;
    }
}

void Ball::SetDirection(ballDirection direction){
    direction_ = direction;
}

int Ball::GetPositionX(){
    return pos_x_;
}

int Ball::GetPositionY(){
    return pos_y_;
}

int Ball::GetWidth(){
    return width_;
}

int Ball::GetHeight(){
    return height_;
}

ballDirection Ball::GetDirection(){
    return direction_;
}

SDL_Rect Ball::GetRectangle(){
    return destination_rectangle_;
}

void Ball::Restart(){
    pos_x_ = start_pos_x_;
    pos_y_ = start_pos_y_;
}
