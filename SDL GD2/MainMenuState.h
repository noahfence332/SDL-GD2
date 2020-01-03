/*#ifndef MainMenuState_h
#define MainMenuState_h
#include <iostream>
#include "MenuState.h"
#include "GameObject.h"

class MainMenuState : public MenuState
{
public:
    
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return sMenuID; }
    
private:
    
    virtual void setCallBacks(const std::vector<Callback>&callbacks);
    static void menuToPlay();
    static void exitFromMenu();
    static const std::string sMenuID;
    std::vector<GameObject*> gameObjects;
};

#endif *//* MainMenuState_h */

