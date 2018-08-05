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
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    std::map<std::string,SDL_Surface*> loadedImage;
    
public:
    Graphics();
    ~Graphics();
    SDL_Surface* loadImage(const std::string &filePath);
    void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
    void flip();
    void clear();
    SDL_Renderer* getRenderer() const;
};

#endif /* grahpics_hpp */
