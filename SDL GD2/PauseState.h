#ifndef PauseState_h
#define PauseState_h

#include <vector>
#include "GameState.h"
#include "MenuState.h"
#include "GameObject.h"

class PauseState : public MenuState
{
public:
    
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateID() const { return pauseID; }
    
    //virtual void setCallBacks(const std::vector<Callback>& callbacks);
    
private:
    
    static void pauseToMain();
    static void resumePlay();
    
    static const std::string pauseID;
    
    std::vector<GameObject*> gameObject;
    
};

#endif /* PauseState_h */
