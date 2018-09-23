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

void Input::KeyDownEvent(const SDL_Event &event){
    pressed_key_[event.key.keysym.scancode] = true;
    held_key_[event.key.keysym.scancode] = true;
}

void Input::KeyUpEvent(const SDL_Event &event){
    released_key_[event.key.keysym.scancode] = true;
    held_key_[event.key.keysym.scancode] = false;
}

void Input::Reset(){
    pressed_key_.clear();
    released_key_.clear();
}

bool Input::WasKeyPressed(SDL_Scancode key){
    return pressed_key_[key];
}

bool Input::WasKeyReleased(SDL_Scancode key){
    return released_key_[key];
}

bool Input::IsKeyHeld(SDL_Scancode key){
    return held_key_[key];
}
