#include <stdio.h>
#include "MenuState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "PlayState.h"

const std::string MenuState::menuID = "MENU";

void MenuState::update()
{
    for(std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++)
    {
        gameObjects[x]->update();
    }
}

void MenuState::render()
{
    for(std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++)
    {
        gameObjects[x]->draw();
    }
}

bool MenuState::onEnter()
{
    std::cout << "entering MenuState" << std::endl;
    
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/playbutton.png", "playbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/exitbutton.png", "exitbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    GameObject * buttonPlay = new MenuButton(new LoaderParams(200, 50, 400, 100, "playbutton"), menuToPlay);
    GameObject * buttonExit = new MenuButton(new LoaderParams(200, 200, 400, 100, "exitbutton"), exitFromMenu);
    
    gameObjects.push_back(buttonPlay);
    gameObjects.push_back(buttonExit);
    
    return true;
}

bool MenuState::onExit()
{
    std::cout << "exiting MenuState" << std::endl;
    
    for(int x = 0; x < gameObjects.size(); x++)
    {
        gameObjects[x]->clean();
    }
    
    gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
    
    return true;
}

void MenuState::menuToPlay()
{
    std::cout << "Play button clicked" << std::endl;
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::exitFromMenu()
{
    std::cout << "Exit button clicked" << std::endl;
    TheGame::Instance()->isRunning = false;
    TheGame::Instance()->clean();
}
