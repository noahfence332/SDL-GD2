#ifndef MenuState_h
#define MenuState_h

#include <iostream>
#include <vector>
#include "GameState.h"
#include "GameObject.h"

class MenuState : public GameState
{
public:
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateID() const { return menuID; }
    
private:
    
    static const std::string menuID;
    
    static void menuToPlay();
    static void exitFromMenu();
    
    std::vector<GameObject*> gameObjects;
    
/*protected:
    typedef void(*Callback)();
    std::vector<Callback> mCallbacks;
    virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
     std::vector<std::string>mTextureIDlist;*/
    
    
};


#endif /* MenuState_h */
