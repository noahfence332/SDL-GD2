#ifndef Game_h
#define Game_h

#include "SDL2/SDL.h"
#include <iostream>
#include "SDL2_image/SDL_image.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>
#include "GameStateMachine.h"



class Game
{
public:
    
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 384;
    
    static Game* Instance()
    {
        if(instance == 0)
        {
            instance = new Game();
            return instance;
        }
        return instance;
    }
    
    bool init(const char* title, int xpos, int ypos, int width, int height, bool flags);
    void run();
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() {return isRunning;}
    bool isRunning;
    
    SDL_Renderer* getRenderer() const { return renderer; }
    GameStateMachine *getStateMachine() { return gameStateMachine; }
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    GameStateMachine* gameStateMachine;
    
    static Game* instance;
    
    int currentFrame;
    
    std::vector<GameObject*> gameObject;
    
    Game(){}
    ~Game(){}
};

typedef Game TheGame;

#endif /* Game_h */
