#include <stdio.h>
#include "PlayState.h"
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "LoaderParams.h"
//#include "StateParser.h"
//#include "GameObjectFactory.h"

const std::string PlayState::playID = "PLAY";

void PlayState::update()
{
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }
    
    for(int x = 0; x < gameObjects.size(); x++)
    {
        gameObjects[x]->update();
    }
    
    if(checkCollision(dynamic_cast<SDLGameObject*>(gameObjects[0]), dynamic_cast<SDLGameObject*>(gameObjects[1])))
    {
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
    }
    
}

void PlayState::render()
{
    for(int x = 0; x < gameObjects.size(); x++)
    {
        gameObjects[x]->draw();
    }
}

bool PlayState::onEnter()
{
    
    std::cout <<"entering PlayState" << std::endl;
    
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/Robin.png", "robin", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/BTLB/assets/Snevil.png", "Snevil", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    Player* player = (new Player(new LoaderParams(300, 320, 32, 32, "robin")));
    Enemy* enemy = (new Enemy(new LoaderParams(0, 320, 60, 60, "Snevil")));
    
    gameObjects.push_back(player);
    gameObjects.push_back(enemy);
    
    /*TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
    TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
    StateParser stateParser;
    stateParser.parseState("test.xml", playID, &gameObjects, &mTextureIDlist);*/
    
    std::cout << "entering PlayState" << std::endl;
    return true;
}

bool PlayState::onExit()
{
    
    std::cout << "exiting PlayState" << std::endl;
    
    for(int x = 0; x < gameObjects.size(); x++)
    {
        gameObjects[x]->clean();
    }
    
    gameObjects.clear();
    
    
    TheTextureManager::Instance()->clearFromTextureMap("robin");
    
    /*for(int i = 0; i < mTextureIDlist.size(); i++)
    {
        TheTextureManager::Instance()->clearFromTextureMap(mTextureIDlist[i]);
    }*/
    
    return true;
}

bool PlayState::checkCollision(SDLGameObject* pPlayer, SDLGameObject* pEnemy)
{
    int leftPlayer, leftEnemy;
    int rightPlayer, rightEnemy;
    int topPlayer, topEnemy;
    int bottomPlayer, bottomEnemy;
    
    leftPlayer = pPlayer->getPosition().getX();
    rightPlayer = leftPlayer + pPlayer->getWidth();
    topPlayer = pPlayer->getPosition().getY();
    bottomPlayer = topPlayer + pPlayer->getHeight();
    
    leftEnemy = pEnemy->getPosition().getX();
    rightEnemy = leftEnemy + pEnemy->getWidth();
    topEnemy = pEnemy->getPosition().getY();
    bottomEnemy = topEnemy + pEnemy->getHeight();

    return !((bottomPlayer <= topEnemy) || (topPlayer >= bottomEnemy) || (rightPlayer <= leftEnemy) || (leftPlayer >= rightEnemy));
}

