/*#include <stdio.h>
#include "MainMenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "StateParser.h"

const std::string MainMenuState::sMenuID = "MENU";

void MainMenuState::update()
{
    for(std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void MainMenuState::render()
{
    for(std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

void MainMenuState::menuToPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::exitFromMenu()
{
    TheGame::Instance()->clean();
}

bool MainMenuState::onEnter()
{
    TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    StateParser stateParser;
    stateParser.parseState("test.xml", sMenuID, &gameObjects, &mTextureIDlist);
    mCallbacks.push_back(0);
    mCallbacks.push_back(menuToPlay);
    mCallbacks.push_back(exitFromMenu);
    
    setCallBacks(mCallbacks);
    std::cout << "entering MenuState" << std::endl;
    return true;
}

bool MainMenuState::onExit()
{
    for(int i = 0; i < mTextureIDlist.size(); i++)
    {
        TheTextureManager::Instance()->clearFromTextureMap(mTextureIDlist[i]);
    }
    return true;
}

void MainMenuState::setCallBacks(const std::vector<Callback>&callbacks)
{
    
    for(std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++)
    {
        if(dynamic_cast<MenuButton*>(gameObjects[i]))
        {
            MenuButton* pButton = dynamic_cast<MenuButton*>(gameObjects[i]);
            pButton->setCallBack(callbacks[pButton->getCallBackID()]);
        }
    }
}
*/
