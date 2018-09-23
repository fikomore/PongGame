//
//  level.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 30.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "level.hpp"
#include "globals.h"

Level::Level(){};

Level::Level(Graphics &graphics, const std::string &filePath, int width, int height){
    texture_ = SDL_CreateTextureFromSurface(graphics.GetRenderer(), graphics.LoadImage(filePath));
    width_ = width;
    height_ = height;
};

void Level::LoadBlock(Graphics &graphics, const std::string &filePath){
block_texture_ = SDL_CreateTextureFromSurface(graphics.GetRenderer(), graphics.LoadImage(filePath));
    SDL_Rect destinationRectangle;
    for(int i=0; i<12; i++){
        std::vector<SDL_Rect> tmp;
        for(int j=0; j<5; j++){
            destinationRectangle.x = globals::kBackgroungBlockSize/2 + globals::kBlockWidth * i;
            destinationRectangle.y = globals::kBackgroungBlockSize/2 + globals::kBlockHeight * j;
            destinationRectangle.w = globals::kBlockWidth;
            destinationRectangle.h = globals::kBlockHeight;
            tmp.push_back(destinationRectangle);
        }
        block_.push_back(tmp);
        tmp.clear();
    }
    start_block_= block_;
}

void Level::Draw(Graphics &graphics){
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    for(int i=0; i<8; i++){ //Namiesto cisla dorobit velkosti 2d pola
        for(int j=0; j<10;j++){ //Namiesto cisla dorobit velkost pola
            if(map_[i][j] != 8){
                sourceRectangle.x = map_[i][j]*width_;
                sourceRectangle.y = 0;
                sourceRectangle.w = width_;
                sourceRectangle.h = height_;
                destinationRectangle.x = j*width_;
                destinationRectangle.y = i*height_;
                destinationRectangle.w = width_;
                destinationRectangle.h = height_;
                graphics.BlitSurface(texture_, &sourceRectangle, &destinationRectangle);
            }
        }
    }
//    Draw blocks on background
    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    sourceRectangle.w = globals::kBlockWidth;
    sourceRectangle.h = globals::kBlockHeight;
    
    for(int i=0; i<block_.size(); i++){
        for(int j=0; j<block_[i].size(); j++){
//            destinationRectangle.x = globals::BG_BLOCK_SIZE/2 + globals::BLOCK_WIDTH * i;
//            destinationRectangle.y = globals::BG_BLOCK_SIZE/2 + globals::BLOCK_HEIGHT * j;
//            destinationRectangle.w = globals::BLOCK_WIDTH;
//            destinationRectangle.h = globals::BLOCK_HEIGHT;
//            tmp.push_back(destinationRectangle);
//            block[i][j].x = globals::BG_BLOCK_SIZE/2 + globals::BLOCK_WIDTH * i;
//            block[i][j].y = globals::BG_BLOCK_SIZE/2 + globals::BLOCK_HEIGHT * j;
//            block[i][j].w = globals::BLOCK_WIDTH;
//            block[i][j].h = globals::BLOCK_HEIGHT;
            graphics.BlitSurface(block_texture_, &sourceRectangle, &block_[i][j]);
        }
    }
}

std::vector<std::vector<SDL_Rect>> &Level::GetBlockVector(){
    return block_;
}

Level::~Level(){};

void Level::Restart(){
    block_ = start_block_;
}
