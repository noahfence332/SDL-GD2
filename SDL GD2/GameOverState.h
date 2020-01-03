#ifndef GameOverState_h
#define GameOverState_h

#include <vector>
#include "GameState.h"
#include "GameObject.h"

class GameOverState : public GameState
{
public:
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateID() const { return gameOverID; }
    
private:
    
    static void gameOverToMain();
    static void restartPlay();
    
    static const std::string gameOverID;
    
    std::vector<GameObject*> gameObjects;
};


#endif /* GameOverState_h */
