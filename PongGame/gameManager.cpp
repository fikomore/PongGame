//
//  gameManager.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 16.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include <iostream>

#include "gameManager.hpp"
#include "input.hpp"
#include "globals.h"

GameManager::GameManager(){
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

void GameManager::gameLoop(){
    bool quit = false;
    Graphics graphics;
    Input input;
    
    this->level = Level(graphics, "lvl.png", globals::BG_BLOCK_SIZE, globals::BG_BLOCK_SIZE);
    this->player = Player(graphics, "bottomPadlle.png", 0, 0, 40, 15, globals::SCREEN_WIDTH/2-globals::PADDLE_WIDTH/2,globals::SCREEN_HEIGHT-globals::BG_BLOCK_SIZE/2 - globals::PADDLE_HEIGHT);
    this->lopta = Ball(graphics, "ball.png", 0, 0, globals::BALL_SIZE, globals::BALL_SIZE, globals::SCREEN_WIDTH/2-globals::BALL_SIZE/2, globals::SCREEN_HEIGHT/2 - globals::BALL_SIZE/2);
    
    lopta.setDirection(DOWN);
    
    SDL_Event event;
    
    int LAST_UPDATE_TIME = SDL_GetTicks();
    while (!quit) {
        input.reset();
        SDL_PollEvent(&event);
        
        if(event.type == SDL_QUIT){
            return;
        }else if(event.type == SDL_KEYDOWN){
            if(event.key.repeat == 0){
                input.keyDownEvent(event);
            }
        }else if(event.type == SDL_KEYUP){
            input.keyUpEvent(event);
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)){
            return;
        }
        if(input.wasKeyPressed(SDL_SCANCODE_LEFT) || input.isKeyHeld(SDL_SCANCODE_LEFT)){
            this->player.moveLeft();
        }
        if(input.wasKeyPressed(SDL_SCANCODE_RIGHT) || input.isKeyHeld(SDL_SCANCODE_RIGHT)){
            this->player.moveRight();
        }
        logic();
        lopta.move();
        draw(graphics);
        
        int CURENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURENT_TIME_MS - LAST_UPDATE_TIME;
        if(ELAPSED_TIME_MS < globals::MAX_FRAME_TIME){
            limitingFPS(globals::MAX_FRAME_TIME-ELAPSED_TIME_MS);
        }
        LAST_UPDATE_TIME = CURENT_TIME_MS;
        
    }
    
}

GameManager::~GameManager(){};

void GameManager::draw(Graphics &graphics){
    graphics.clear();
    this->level.draw(graphics);
    this->player.draw(graphics);
    this->lopta.draw(graphics);
    graphics.flip();
}

void GameManager::logic(){
//    Odrazanie z hora
    if (lopta.getPositionY() == globals::BG_BLOCK_SIZE/2) {
        if(lopta.getDirection() == LEFT_UP)
            lopta.setDirection(LEFT_DOWN);
        else if(lopta.getDirection() == RIGHT_UP)
            lopta.setDirection(RIGHT_DOWN);
        else
            lopta.setDirection(DOWN);
    }
//    Odrazanie z lava
    if(lopta.getPositionX() == globals::BG_BLOCK_SIZE/2){
        if(lopta.getDirection() == LEFT_DOWN)
            lopta.setDirection(RIGHT_DOWN);
        if(lopta.getDirection() == LEFT_UP)
            lopta.setDirection(RIGHT_UP);
    }
//    Odrazanie z prava
    if(lopta.getPositionX() == (globals::SCREEN_WIDTH - globals::BG_BLOCK_SIZE/2 - globals::BALL_SIZE)){
        if (lopta.getDirection() == RIGHT_DOWN)
            lopta.setDirection(LEFT_DOWN);
        if(lopta.getDirection() == RIGHT_UP)
            lopta.setDirection(LEFT_UP);
    }
//    Odrazanie zo spodu
//    if(lopta.getPositionY() == (globals::SCREEN_HEIGHT - globals::BG_BLOCK_SIZE/2 - globals::BALL_SIZE)){
//        if (lopta.getDirection() == LEFT_DOWN)
//            lopta.setDirection(LEFT_UP);
//        else if(lopta.getDirection() == RIGHT_DOWN)
//            lopta.setDirection(RIGHT_UP);
//        else
//            lopta.setDirection(UP);
//
//    }
    if(checkCollision(lopta, player)){
        if (lopta.getPositionX() <= player.getPositionX() - lopta.getWidth()/2 && lopta.getPositionX() <= player.getPositionX() + lopta.getWidth()){
            lopta.setDirection(LEFT_UP);
        }
        else if(lopta.getPositionX() >= player.getPositionX() + player.getWidth() - lopta.getWidth()){
            lopta.setDirection(RIGHT_UP);
        }
        else if(lopta.getPositionX() + lopta.getWidth()/2 == player.getPositionX() + player.getWidth()/2){
            lopta.setDirection(UP);
        }
        else {
            if(lopta.getDirection() == LEFT_DOWN)
                lopta.setDirection(LEFT_UP);
            else if (lopta.getDirection() == RIGHT_DOWN)
                lopta.setDirection(RIGHT_UP);
            else
                lopta.setDirection(UP);
        }
    }
    
}

bool GameManager::checkCollision(Ball ball, Player player){
    if((ball.getPositionY() + ball.getHeight()) == player.getPositionY()){
        if((ball.getPositionX() >= player.getPositionX() - ball.getWidth()) &&
           (ball.getPositionX() <= player.getPositionX() + player.getWidth() + ball.getWidth())){
            return true;
        }
    }
    return false;
}

void GameManager::limitingFPS(float elapsedTime){
    SDL_Delay(elapsedTime);
}
