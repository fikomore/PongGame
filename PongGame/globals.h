//
//  globals.h
//  PongGame
//
//  Created by Fikrim Kabashi on 2.8.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef globals_h
#define globals_h

namespace globals {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 512;
    const int BG_BLOCK_SIZE = 64;
    const int PADDLE_WIDTH = 40;
    const int PADDLE_HEIGHT = 15;
    const int BALL_SIZE = 20;
    const int FPS = 180;
    const int MAX_FRAME_TIME = 5*1000/FPS;
    
}

enum ballDirection {STOP = 0, UP = 1, LEFT_UP = 2, RIGHT_UP = 3, DOWN = 4, LEFT_DOWN = 5, RIGHT_DOWN = 6 };
#endif /* globals_h */
