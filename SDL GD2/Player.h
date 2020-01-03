#ifndef Player_h
#define Player_h

#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "LoaderParams.h"
//#include "GameObjectFactory.h"

class Player : public SDLGameObject
{
    
public:
    Player(const LoaderParams* Params);
    
    virtual void draw();
    virtual void drawFrame();
    virtual void update();
    virtual void clean();
    //virtual void load(const LoaderParams* Params);
    
private:
    void handleInput();
    
};

/*class PlayerCreator : public BaseCreator
{
  GameObject* createGameObject() const
    {
        return new Player();
    }
};*/


#endif /* Player_h */
