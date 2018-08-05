//
//  level.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 30.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "level.hpp"

Level::Level(){};

Level::Level(Graphics &graphics, const std::string &filePath, int width, int height){
    texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    this->width = width;
    this->height = height;
};

void Level::draw(Graphics &graphics){
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    for(int i=0; i<8; i++){ //Namiesto cisla dorobit velkosti 2d pola
        for(int j=0; j<10;j++){ //Namiesto cisla dorobit velkost pola
            if(map[i][j] != 8){
                sourceRectangle.x = map[i][j]*this->width;
                sourceRectangle.y = 0;
                sourceRectangle.w = this->width;
                sourceRectangle.h = this->height;
                destinationRectangle.x = j*this->width;
                destinationRectangle.y = i*this->height;
                destinationRectangle.w = this->width;
                destinationRectangle.h = this->height;
                graphics.blitSurface(texture, &sourceRectangle, &destinationRectangle);
            }
        }
    }
}

Level::~Level(){};
