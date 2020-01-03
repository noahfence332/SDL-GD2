#ifndef Enemy_h
#define Enemy_h

#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject
{
    
public:
    Enemy(const LoaderParams* Params);
    
    virtual void draw();
    virtual void drawFrame();
    virtual void update();
    virtual void clean();
    //virtual void load(const LoaderParams* Params);
    
private:
    void handleInput();
};

/*class EnemyCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Enemy();
    }
};*/

#endif /* Enemy_h */
