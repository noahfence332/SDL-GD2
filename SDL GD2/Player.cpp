#include <stdio.h>
#include "Player.h"
#include "InputHandler.h"
#include "Game.h"

Player::Player(const LoaderParams* Params) : SDLGameObject(Params) {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::drawFrame()
{
    SDLGameObject::drawFrame();
}

void Player::update()
{
    mVelocity.setX(0);
    mVelocity.setY(0);
    
    handleInput();
    
    mCurrentFrame = int(((SDL_GetTicks() / 100) % 1));
    
    SDLGameObject::update();
}

void Player::handleInput()
{
    InputHandler* inputHandler = TheInputHandler::Instance();
    
    if(inputHandler->isKeyDown(SDL_SCANCODE_A))
    {
        mVelocity.setX(-2);
    }
    if(inputHandler->isKeyDown(SDL_SCANCODE_D))
    {
        mVelocity.setX(2);
    }
    
    if(inputHandler->isKeyDown(SDL_SCANCODE_S))
    {
        mVelocity.setY(2);
    }
    if(inputHandler->isKeyDown(SDL_SCANCODE_W))
    {
        mVelocity.setY(-2);
    }

}

void Player::clean(){}

/*void Player::load(const LoaderParams* Params)
{
    SDLGameObject::load(Params);
}*/
