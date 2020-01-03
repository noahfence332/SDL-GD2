#include <stdio.h>
#include "PauseState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "LoaderParams.h"
//#include "MainMenuState.h"
//#include "StateParser.h"

const std::string PauseState::pauseID = "PAUSE";

void PauseState::pauseToMain()
{
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::resumePlay()
{
    TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
    for(std::vector<GameObject*>::size_type x = 0; x < gameObject.size(); x++)
    {
        gameObject[x]->update();
    }
}

void PauseState::render()
{
    for(std::vector<GameObject*>::size_type x = 0; x < gameObject.size(); x++)
    {
        gameObject[x]->draw();
    }
}

bool PauseState::onEnter()
{
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/continuebutton.png", "continuebutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/mainmenubutton.png", "mainmenubutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    GameObject* buttonPlay = new MenuButton(new LoaderParams(100, 150, 200, 80, "continuebutton"), resumePlay);
    GameObject* buttonPause = new MenuButton(new LoaderParams(500, 150, 200, 80, "mainmenubutton"), pauseToMain);
    
    gameObject.push_back(buttonPlay);
    gameObject.push_back(buttonPause);
    
    /*TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    StateParser stateParser;
    stateParser.parseState("test.xml", pauseID, &gameObject, &mTextureIDlist);
    mCallbacks.push_back(0);
    mCallbacks.push_back(pauseToMain);
    mCallbacks.push_back(resumePlay);
    setCallBacks(mCallbacks);*/
    
    std::cout << "entering PauseState" << std::endl;
    
    return true;
}

bool PauseState::onExit()
{
    for(int x = 0; x < gameObject.size(); x++)
    {
        gameObject[x]->clean();
    }
    
    gameObject.clear();
    
    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("pausebutton");
    
    /*for(int x = 0; x < mTextureIDlist.size(); x++)
    {
        TheTextureManager::Instance()->clearFromTextureMap(mTextureIDlist[x]);
    }*/
    
    std::cout << "exiting PauseState" << std::endl;
    
    return true;
}

/*void PauseState::setCallBacks(const std::vector<Callback>&callbacks)
{
    for (int x = 0; x < gameObjects.size(); x++)
    {
        if (dynamic_cast<MenuButton*>(gameObjects[x]))
        {
            MenuButton* pButton = dynamic_cast<MenuButton*>(gameObjects[x]);
            pButton->setCallBack(callbacks[pButton->getCallbackID()]);
        }
    }
}*/
