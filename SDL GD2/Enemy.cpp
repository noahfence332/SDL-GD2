#include <stdio.h>
#include "Enemy.h"
#include "Player.h"
#include "InputHandler.h"
#include "SDLGameObject.h"

Enemy::Enemy(const LoaderParams* Params) : SDLGameObject(Params) {}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::drawFrame()
{
    SDLGameObject::drawFrame();
}

void Enemy::update()
{
    mVelocity.setX(0);
    mVelocity.setY(0);
    
    handleInput();
    
    mCurrentFrame = int(((SDL_GetTicks() / 100) % 1));
    
    SDLGameObject::update();
}

void Enemy::handleInput()
{
   // InputHandler* inputHandler = TheInputHandler::Instance();
    
}

void Enemy::clean(){}

/*void Enemy::load(const LoaderParams* Params)
{
    SDLGameObject::load(Params);
}*/
