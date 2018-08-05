//
//  input.hpp
//  PongGame
//
//  Created by Fikrim Kabashi on 17.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef input_hpp
#define input_hpp

#include <map>
#include <SDL2/SDL.h>


class Input{
private:
    std::map<SDL_Scancode, bool> pressedKey;
    std::map<SDL_Scancode, bool> releasedKey;
    std::map<SDL_Scancode, bool> heldKey;
    
public:
    Input();
    ~Input();
    
    void keyDownEvent(const SDL_Event& event);
    void keyUpEvent(const SDL_Event& event);
    void reset();
    
    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
};

#endif /* input_hpp */
