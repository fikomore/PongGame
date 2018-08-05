//
//  input.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 17.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "input.hpp"

Input::Input(){};

Input::~Input(){};

void Input::keyDownEvent(const SDL_Event &event){
    this->pressedKey[event.key.keysym.scancode] = true;
    this->heldKey[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event &event){
    this->releasedKey[event.key.keysym.scancode] = true;
    this->heldKey[event.key.keysym.scancode] = false;
}

void Input::reset(){
    pressedKey.clear();
    releasedKey.clear();
}

bool Input::wasKeyPressed(SDL_Scancode key){
    return this->pressedKey[key];
}

bool Input::wasKeyReleased(SDL_Scancode key){
    return this->releasedKey[key];
}

bool Input::isKeyHeld(SDL_Scancode key){
    return this->heldKey[key];
}
