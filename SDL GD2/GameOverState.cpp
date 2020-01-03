#include <stdio.h>
#include <string>
#include "GameOverState.h"
#include "Game.h"
#include "TextureManager.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "PlayState.h"

const std::string GameOverState::gameOverID = "GAMEOVER";

void GameOverState::gameOverToMain()
{
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::restartPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::update()
{
    for(int x = 0; x < gameObjects.size(); x++)
    {
        gameObjects[x]->update();
    }
}

void GameOverState::render()
{
    for(int x = 0; x < gameObjects.size(); x++)
    {
        gameObjects[x]->draw();
    }
}

bool GameOverState::onEnter()
{
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/gameovertext.png", "gameovertext", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/mainbutton.png", "mainbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/restartbutton.png", "restartbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(300, 150, 200, 100, "gameovertext"), 2);
    GameObject* buttonMainMenu = new MenuButton(new LoaderParams(200, 250, 100, 80, "mainbutton"), gameOverToMain);
    GameObject* buttonRestart = new MenuButton(new LoaderParams(500, 250, 100, 80, "restartbutton"), restartPlay);
    
    gameObjects.push_back(gameOverText);
    gameObjects.push_back(buttonMainMenu);
    gameObjects.push_back(buttonRestart);
    
    std::cout << "entering GameOverState" << std::endl;
    
    return true;
}
                         
bool GameOverState::onExit()
{
    
    std::cout << "exiting GameOverState" << std::endl;
    
    return true;
}
    
