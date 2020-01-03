#include <stdio.h>
#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams* Params, void (*pOnClickEvent)()) : SDLGameObject(Params), OnClickEvent(pOnClickEvent)
{
    mCurrentFrame = MOUSE_OUT;
}


void MenuButton::draw()
{
    SDLGameObject::draw();
}

void MenuButton::update()
{
    Vector2D* mousePos = TheInputHandler::Instance()->getMousePosition();
    
    if(mousePos->getX() < (mPosition.getX() + mWidth) && mousePos->getX() > mPosition.getX() && mousePos->getY() < (mPosition.getY() + mHeight) && mousePos->getY() > mPosition.getY())
    {
        mCurrentFrame = MOUSE_OVER;
        
        if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && released)
        {
            mCurrentFrame = CLICKED;
            OnClickEvent();
            //mCallback();
            released = false;
        }
        /*else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT))
        {
            released = true;
            mCurrentFrame = MOUSE_OVER;
        }*/
    }
    /*else
    {
        mCurrentFrame = MOUSE_OVER;
    }*/
}

/*void MenuButton::load(const LoaderParams *Params)
{
    SDLGameObject::load(Params);
   // mCallBackID = Params->getCallBackID();
}*/
