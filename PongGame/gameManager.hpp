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
    void gameLoop();
    void draw(Graphics &graphics);
    void logic();
    bool checkCollision(Ball ball, Player player);
    void limitingFPS(float elapsedTime);
public:
    GameManager();
    ~GameManager();
    
    Player player;
    Ball lopta;
    Level level;
};

#endif /* gameManager_hpp */
