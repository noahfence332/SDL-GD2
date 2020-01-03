#include <stdio.h>
#include "GameStateMachine.h"

void GameStateMachine::update()
{
    if(mGameStates.empty())
    {
        return;
    }
    
    //mGameStates.back()->getStateID();
    mGameStates.back()->update();
}

void GameStateMachine::render()
{
    if(mGameStates.empty())
    {
        return;
    }
    
    mGameStates.back()->render();
}

void GameStateMachine::pushState(GameState* pState)
{
    mGameStates.push_back(pState);
    mGameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState* pState)
{
    if(!mGameStates.empty())
    {
        if(mGameStates.back()->getStateID() == pState->getStateID())
        {
            return;
        }
        
        popState();
    }
    
    mGameStates.push_back(pState);
    mGameStates.back()->onEnter();
}
       
void GameStateMachine::popState()
{
    if(mGameStates.empty())
    {
        return;
    }
    
    if(mGameStates.back()->onExit())
    {
        mGameStates.pop_back();
    }
}
