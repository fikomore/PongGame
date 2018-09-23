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
    std::map<SDL_Scancode, bool> pressed_key_;
    std::map<SDL_Scancode, bool> released_key_;
    std::map<SDL_Scancode, bool> held_key_;
    
public:
    Input();
    ~Input();
    
    void KeyDownEvent(const SDL_Event& event);
    void KeyUpEvent(const SDL_Event& event);
    void Reset();
    
    bool WasKeyPressed(SDL_Scancode key);
    bool WasKeyReleased(SDL_Scancode key);
    bool IsKeyHeld(SDL_Scancode key);
};

#endif /* input_hpp */
