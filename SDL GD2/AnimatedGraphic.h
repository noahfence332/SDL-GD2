#ifndef AnimatedGraphic_h
#define AnimatedGraphic_h

#include "SDLGameObject.h"
#include "LoaderParams.h"
//#include "GameObjectFactory.h"

class AnimatedGraphic : public SDLGameObject
{
public:
    
    AnimatedGraphic(const LoaderParams* Params);
    
    virtual void draw();
    virtual void update();
    virtual void clean() {}
    //void load(const LoaderParams* Params);
    
private:
    
    int animateSpeed;
};

/*class AnimatedGraphicCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new AnimatedGraphic();
    }
};*/
#endif /* AnimatedGraphic_h */
