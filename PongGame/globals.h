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
    const int kScreenWidth = 640;
    const int kScreenHeight = 512;
    const int kBackgroungBlockSize = 64;
    const int kBlockWidth = 48;
    const int kBlockHeight = 15;
    const int kPaddleWidth = 40;
    const int kPaddleHeight = 15;
    const int kBallSize = 20;
    const int kFps = 150;
    const int kMaxFrameTime = 5*1000/kFps;
    
}

enum ballDirection {STOP = 0, UP = 1, LEFT_UP = 2, RIGHT_UP = 3, DOWN = 4, LEFT_DOWN = 5, RIGHT_DOWN = 6 };
#endif /* globals_h */
