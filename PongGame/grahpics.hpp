//
//  grahpics.hpp
//  PongGame
//
//  Created by Fikrim Kabashi on 16.7.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef grahpics_hpp
#define grahpics_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <map>
#include <string>


class Graphics{
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    
    std::map<std::string,SDL_Surface*> loaded_image_;
    
public:
    Graphics();
    ~Graphics();
    SDL_Surface* LoadImage(const std::string &filePath);
    void BlitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
    void Flip();
    void Clear();
    SDL_Renderer* GetRenderer() const;
};

#endif /* grahpics_hpp */
