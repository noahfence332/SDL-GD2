#ifndef GameStateMachine_h
#define GameStateMachine_h

#include <vector>
#include "GameState.h"

class GameStateMachine
{
public:
    
    void update();
    void render();
    
    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();
    
private:
    
    std::vector<GameState*> mGameStates;
};


#endif /* GameStateMachine_h */
