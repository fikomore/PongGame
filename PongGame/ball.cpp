//
//  ball.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 17.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "ball.hpp"

Ball::Ball(){};

Ball::Ball(Graphics &graphics,const std::string &filePath, int sourceX, int sourceY, int width, int height, int posX, int posY)
{
    this->sourceRectangle.x = sourceX;
    this->sourceRectangle.y = sourceY;
    this->sourceRectangle.w = width;
    this->sourceRectangle.h = height;
    
    this->direction = STOP;
    
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    
    texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if(texture == nullptr){
        printf("\nError: unable to load BALL image.\n");
    }
}

Ball::~Ball(){};

void Ball::draw(Graphics &graphics) {
    SDL_Rect destinationRectangle;
    destinationRectangle.x = this->posX;
    destinationRectangle.y = this->posY;
    destinationRectangle.w = this->sourceRectangle.w;
    destinationRectangle.h = this->sourceRectangle.h;
    graphics.blitSurface(texture, &this->sourceRectangle, &destinationRectangle);
}

void Ball::move(){
    switch (direction) {
        case STOP:
            break;
        case UP:
            posY--;
            break;
        case DOWN:
            posY++;
            break;
        case LEFT_UP:
            posX--;
            posY--;
            break;
        case RIGHT_UP:
            posX++;
            posY--;
            break;
        case LEFT_DOWN:
            posX--;
            posY++;
            break;
        case RIGHT_DOWN:
            posX++;
            posY++;
            break;
        default:
            break;
    }
}

void Ball::setDirection(ballDirection direction){
    this->direction = direction;
}

int Ball::getPositionX(){
    return  this->posX;
}

int Ball::getPositionY(){
    return this->posY;
}

int Ball::getWidth(){
    return this->width;
}

int Ball::getHeight(){
    return this->height;
}

ballDirection Ball::getDirection(){
    return this->direction;
}

