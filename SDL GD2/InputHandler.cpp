#include <stdio.h>
#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler *InputHandler::instance = 0;

TheInputHandler::InputHandler()
{
    onKeyDown();
    mousePosition = new Vector2D(0,0);
    
    for(int x = 0; x < 3 ; x++)
    {
        mouseButtonStates.push_back(false);
    }
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(mKeystates != 0)
    {
        if(mKeystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void InputHandler::update()
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                TheGame::Instance()->isRunning = false;
                break;
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;
            case SDL_KEYDOWN:
                onKeyDown();
                break;
            case SDL_KEYUP:
                onKeyUp();
                break;
            default:
                break;
        }
    }
}

void InputHandler::onKeyDown()
{
    mKeystates = (Uint8*) SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
    mKeystates = (Uint8*) SDL_GetKeyboardState(0);
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
    return mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition()
{
    return mousePosition;
}

void InputHandler::onMouseMove(SDL_Event &event)
{
    mousePosition->setX(event.motion.x);
    mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates[LEFT] = true;
    }
    
    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = true;
    }
    
    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = true;
    }
}

void InputHandler::onMouseButtonUp(SDL_Event &event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates[LEFT] = false;
    }
    
    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = false;
    }
    
    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = false;
    }
}
