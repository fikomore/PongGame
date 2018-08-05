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
    window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(this->window, -1, 0);
};

Graphics::~Graphics(){
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath){
    if(this->loadedImage.count(filePath) == 0){
        loadedImage[filePath] = IMG_Load(filePath.c_str());
    }
    return loadedImage[filePath];
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle){
    SDL_RenderCopy(this->renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip(){
    SDL_RenderPresent(this->renderer);
}

void Graphics::clear(){
    SDL_RenderClear(this->renderer);
}

SDL_Renderer* Graphics::getRenderer() const{
    return this->renderer;
}
