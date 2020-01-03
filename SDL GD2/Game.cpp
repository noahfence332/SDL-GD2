#include <stdio.h>
#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"
#include "MenuState.h"

Game* Game::instance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
        
        if ((window !=0 ))
        {
            std::cout<< "window creation success\n";
            renderer = SDL_CreateRenderer(window, -1, 0);
        
            if(renderer)
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }
            else
            {
                std::cout<< "renderer init fail\n";
                return false;
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false;
        }
        
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false;
    }
    
    std::cout << "init success\n";
    
    isRunning = true;
    
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/Robin.png", "robin", renderer))
    {
        return false;
    }
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/Snevil.png", "Snevil", renderer))
    {
        return false;
    }
    
    gameStateMachine = new GameStateMachine();
    gameStateMachine->changeState(new MenuState());
    
    Player* player = (new Player(new LoaderParams(300, 320, 32, 32, "robin")));
    Enemy* enemy = (new Enemy(new LoaderParams(0, 320, 60, 60, "Snevil")));
                                                   
    gameObject.push_back(player);
    gameObject.push_back(enemy);
    
    return true;
}

void Game::run()
{
    const int FPS = 60;
    const int DELAY_TIME = 1000.0f / FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    while(running())
    {
        frameStart = SDL_GetTicks();
        
        handleEvents();
        update();
        render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if(frameTime < DELAY_TIME)
        {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }
}

void Game::update()
{
    /*for(std::vector<GameObject*>::size_type x = 0; x != gameObject.size(); x++)
    {
        gameObject[x]->update();
    }*/
    
    gameStateMachine->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    /*for(std::vector<GameObject*>::size_type x = 0; x != gameObject.size(); x++)
    {
        gameObject[x]->draw();
    }*/
    
    gameStateMachine->render();
    
    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

void Game::clean()
{
    isRunning = false;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
