#ifndef PlayState_h
#define PlayState_h

#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include <vector>


class PlayState : public GameState
{
public:
    
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateID() const { return playID; }
    
private:
    
    static const std::string playID;
    
    std::vector<GameObject*> gameObjects;
    
    bool checkCollision(SDLGameObject* pPlayer, SDLGameObject* pEnemy);
    
};


#endif /* PlayState_h */
