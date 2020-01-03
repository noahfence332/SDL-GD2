#ifndef TextureManager_h
#define TextureManager_h
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <string>
#include <iostream>
#include <map>
#include "SDL2_image/SDL_image.h"

class TextureManager
{
public:
    
    ~TextureManager(){}
    
    static TextureManager* Instance()
    {
        if(instance == 0)
        {
            instance = new TextureManager();
            return instance;
        }
        return instance;
    }
    
    bool load(std::string fileName, std::string id, SDL_Renderer* renderer);
    
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void clearFromTextureMap(std::string id);
    
private:
    
    TextureManager(){}
    
    static TextureManager* instance;
    
    std::map<std::string, SDL_Texture*> textureMap;
};

typedef TextureManager TheTextureManager;


#endif /* TextureManager_h */
