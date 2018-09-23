//
//  gameManager.cpp
//  PongGame
//
//  Created by Fikrim Kabashi on 16.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include <iostream>
#include <time.h>

#include "gameManager.hpp"
#include "input.hpp"
#include "globals.h"

GameManager::GameManager() : new_game_(true){
    SDL_Init(SDL_INIT_EVERYTHING);
    srand (time(NULL));
    GameLoop();
}

void GameManager::GameLoop(){
    bool quit = false;
    Graphics graphics;
    Input input;
    
    level_ = Level(graphics, "lvl.png", globals::kBackgroungBlockSize, globals::kBackgroungBlockSize);
    level_.LoadBlock(graphics, "block.png");
    player_ = Player(graphics, "bottomPadlle.png", 0, 0, 40, 15, globals::kScreenWidth/2-globals::kPaddleWidth/2,globals::kScreenHeight-globals::kBackgroungBlockSize/2 - globals::kPaddleHeight);
    ball_ = Ball(graphics, "ball.png", 0, 0, globals::kBallSize, globals::kBallSize, globals::kScreenWidth/2-globals::kBallSize/2, globals::kScreenHeight/2 - globals::kBallSize/2);
    
//    Nastavenie smeru lopty
    //lopta.setDirection(DOWN);
    
    SDL_Event event;
    
    int LAST_UPDATE_TIME = SDL_GetTicks();
    while (!quit) {
        input.Reset();
        SDL_PollEvent(&event);
        
        if(event.type == SDL_QUIT){
            return;
        }else if(event.type == SDL_KEYDOWN){
            if(event.key.repeat == 0){
                input.KeyDownEvent(event);
            }
        }else if(event.type == SDL_KEYUP){
            input.KeyUpEvent(event);
        }
        if(input.WasKeyPressed(SDL_SCANCODE_ESCAPE)){
            return;
        }
        if(input.WasKeyPressed(SDL_SCANCODE_LEFT) || input.IsKeyHeld(SDL_SCANCODE_LEFT)){
            if(new_game_){
                ball_.SetDirection(static_cast<ballDirection>((rand()%5 + 1)));
                new_game_ = false;
            }
            player_.MoveLeft();
        }
        if(input.WasKeyPressed(SDL_SCANCODE_RIGHT) || input.IsKeyHeld(SDL_SCANCODE_RIGHT)){
            if(new_game_){
                ball_.SetDirection(static_cast<ballDirection>((rand()%5 + 1)));
                new_game_ = false;
            }
            player_.MoveRight();
        }
        Logic();
        ball_.Move();
        if(level_.GetBlockVector().size() == 0){
            Restart();
        }
        Draw(graphics);
        
        int CURENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURENT_TIME_MS - LAST_UPDATE_TIME;
        if(ELAPSED_TIME_MS < globals::kMaxFrameTime){
            LimitingFPS(globals::kMaxFrameTime-ELAPSED_TIME_MS);
        }
        LAST_UPDATE_TIME = CURENT_TIME_MS;
        
    }
    
}

GameManager::~GameManager(){};

void GameManager::Draw(Graphics &graphics){
    graphics.Clear();
    level_.Draw(graphics);
    player_.Draw(graphics);
    ball_.Draw(graphics);
    graphics.Flip();
}

void GameManager::Logic(){
//    Odrazanie z lava
    if(ball_.GetPositionX() == globals::kBackgroungBlockSize/2){
        if(ball_.GetDirection() == LEFT_DOWN)
            ball_.SetDirection(RIGHT_DOWN);
        if(ball_.GetDirection() == LEFT_UP)
            ball_.SetDirection(RIGHT_UP);
    }
//    Odrazanie z prava
    if(ball_.GetPositionX() == (globals::kScreenWidth - globals::kBackgroungBlockSize/2 - globals::kBallSize)){
        if (ball_.GetDirection() == RIGHT_DOWN)
            ball_.SetDirection(LEFT_DOWN);
        if(ball_.GetDirection() == RIGHT_UP)
            ball_.SetDirection(LEFT_UP);
    }
    //    Odrazanie z hora
    if (ball_.GetPositionY() == globals::kBackgroungBlockSize/2) {
        if(ball_.GetDirection() == LEFT_UP)
            ball_.SetDirection(LEFT_DOWN);
        else if(ball_.GetDirection() == RIGHT_UP)
            ball_.SetDirection(RIGHT_DOWN);
        else
            ball_.SetDirection(DOWN);
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
    //Odrazenie od padla
    //Vylepsit ma to buggy
    if(CheckCollision(ball_, player_)){
        if (ball_.GetPositionX() <= player_.GetPositionX() - ball_.GetWidth()/2 && ball_.GetPositionX() <= player_.GetPositionX() + ball_.GetWidth()){
            ball_.SetDirection(LEFT_UP);
        }
        else if(ball_.GetPositionX() >= player_.GetPositionX() + player_.GetWidth() - ball_.GetWidth()){
            ball_.SetDirection(RIGHT_UP);
        }
        else if(ball_.GetPositionX() + ball_.GetWidth()/2 == player_.GetPositionX() + player_.GetWidth()/2){
            ball_.SetDirection(UP);
        }
        else {
            if(ball_.GetDirection() == LEFT_DOWN)
                ball_.SetDirection(LEFT_UP);
            else if (ball_.GetDirection() == RIGHT_DOWN)
                ball_.SetDirection(RIGHT_UP);
            else
                ball_.SetDirection(UP);
        }
    }
    
    
    for(int i = 0; i < level_.GetBlockVector().size(); i++){
        for(int j = 0; j < level_.GetBlockVector()[i].size(); j++){
            if(HandleCollisionWithBlock(level_.GetBlockVector()[i][j], ball_.GetRectangle())){
                level_.GetBlockVector()[i][j] = level_.GetBlockVector()[i].back();
                level_.GetBlockVector()[i].pop_back();
            }
        }
    }
    
//    for (int i = 0; i < level.getBlockVector().size(); i++) {
//        for(int j = 0; j < level.getBlockVector()[i].size(); j++){
//            if(handleCollisionWithBlock(level.getBlockVector()[i][j], lopta.getRectangle()))
//                level.getBlockVector()[i][j];
//        }
//    }
    
}


bool GameManager::CheckCollision(Ball ball, Player player){
    if((ball.GetPositionY() + ball.GetHeight()) == player.GetPositionY()){
        if((ball.GetPositionX() >= player.GetPositionX() - ball.GetWidth()) &&
           (ball.GetPositionX() <= player.GetPositionX() + player.GetWidth() + ball.GetWidth())){
            return true;
        }
    }
    return false;
}

void GameManager::LimitingFPS(float elapsedTime){
    SDL_Delay(elapsedTime);
}

bool GameManager::HandleCollisionWithBlock(SDL_Rect block, SDL_Rect ball){
    int leftBlock, leftBall;
    int rightBlock, rightBall;
    int topBlock, topBall;
    int bottomBlock, bottomBall;
    
//    Callculate the side of the block
    leftBlock = block.x;
    rightBlock = block.x + block.w;
    topBlock = block.y;
    bottomBlock = block.y + block.h;
    
//    Callculate the side of ball
    leftBall = ball.x;
    rightBall = ball.x + ball.w;
    topBall = ball.y;
    bottomBall = ball.y + ball.h;
    
    if(bottomBlock <= topBall){
        return false;
    }
    if(rightBlock <= leftBall){
        return false;
    }
    if(leftBlock >= rightBall){
        return false;
    }
    if(topBlock >= bottomBall){
        return false;
    }
    if((rightBlock == leftBall + 1 && bottomBlock >= topBall) || (rightBlock == leftBall + 1 && topBlock <= bottomBall)) {
        if(ball_.GetDirection() == LEFT_UP)
            ball_.SetDirection(RIGHT_UP);
        else if(ball_.GetDirection() == LEFT_DOWN)
            ball_.SetDirection(RIGHT_DOWN);
    }
    else if((leftBlock == rightBall + 1 && bottomBlock >= topBall) || (leftBlock == rightBall + 1 && topBlock <= bottomBall)) {
        if(ball_.GetDirection() == LEFT_UP)
            ball_.SetDirection(RIGHT_UP);
        else if(ball_.GetDirection() == LEFT_DOWN)
            ball_.SetDirection(RIGHT_DOWN);
    }
    else if(bottomBlock >= topBall){
        if(ball_.GetDirection() == LEFT_UP)
            ball_.SetDirection(LEFT_DOWN);
        else if(ball_.GetDirection() == RIGHT_UP)
            ball_.SetDirection(RIGHT_DOWN);
        else if(ball_.GetDirection() == UP)
            ball_.SetDirection(DOWN);
    }
    else if(topBlock <= bottomBall){
        if(ball_.GetDirection() == RIGHT_DOWN)
            ball_.SetDirection(RIGHT_UP);
        else if(ball_.GetDirection() == LEFT_DOWN)
            ball_.SetDirection(LEFT_UP);
    }
    return true;
}

void GameManager::Restart(){
    ball_.Restart();
    player_.Restart();
    level_.Restart();
    new_game_ = true;
}
