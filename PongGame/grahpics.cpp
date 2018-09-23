//
//  grahpics.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 16.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "grahpics.hpp"
#include "globals.h"

Graphics::Graphics(){
    window_ = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, globals::kScreenWidth, globals::kScreenHeight, 0);
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
};

Graphics::~Graphics(){
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
}

SDL_Surface* Graphics::LoadImage(const std::string &filePath){
    if(loaded_image_.count(filePath) == 0){
        loaded_image_[filePath] = IMG_Load(filePath.c_str());
    }
    return loaded_image_[filePath];
}

void Graphics::BlitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle){
    SDL_RenderCopy(renderer_, texture, sourceRectangle, destinationRectangle);
}

void Graphics::Flip(){
    SDL_RenderPresent(renderer_);
}

void Graphics::Clear(){
    SDL_RenderClear(renderer_);
}

SDL_Renderer* Graphics::GetRenderer() const{
    return renderer_;
}
