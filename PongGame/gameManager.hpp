//
//  gameManager.hpp
//  PongGame
//
//  Created by Fikrim Kabashi on 16.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef gameManager_hpp
#define gameManager_hpp

#include <SDL2/SDL.h>
#include "player.hpp"
#include "grahpics.hpp"
#include "ball.hpp"
#include "level.hpp"

class GameManager{
private:
    void GameLoop();
    void Draw(Graphics &graphics);
    void Logic();
    bool CheckCollision(Ball ball, Player player);
    bool HandleCollisionWithBlock(SDL_Rect block, SDL_Rect ball);
    void LimitingFPS(float elapsedTime);
    void Restart();
    bool new_game_;
public:
    GameManager();
    ~GameManager();
    
    Player player_;
    Ball ball_;
    Level level_;
};

#endif /* gameManager_hpp */
