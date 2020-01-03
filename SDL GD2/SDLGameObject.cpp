#include <stdio.h>
#include "Game.h"
#include "Vector2D.h"
#include "SDLGameObject.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* Params) : GameObject(Params),
mPosition(Params->getX(), Params->getY()),
mVelocity(0,0),
mAcceleration(0,0){}

void SDLGameObject::draw()
{
    TheTextureManager::Instance()->draw(mTextureID, (int)mPosition.getX(), (int)mPosition.getY(), mWidth, mHeight, TheGame::Instance()->getRenderer());
}

void SDLGameObject::drawFrame()
{
    TheTextureManager::Instance()->drawFrame(mTextureID, (int)mPosition.getX(), (int)mPosition.getY(), mWidth, mHeight, mCurrentRow, mCurrentFrame, TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    mPosition += mVelocity;
    mVelocity += mAcceleration;
}

void SDLGameObject::clean(){}

/*void SDLGameObject::load(const LoaderParams* Params)
{
    mPosition = Vector2D(Params->getX(), Params->getY());
    mVelocity = Vector2D(0,0);
    mAcceleration = Vector2D(0,0);
    mWidth = Params->getWidth();
    mHeight = Params->getHeight();
    mTextureID = Params->getTextureID();
    mCurrentRow = 1;
    mCurrentFrame = 1;
    mNumFrames = Params->getNumFrames();
}*/
