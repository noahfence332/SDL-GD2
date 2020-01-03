#ifndef MenuButton_h
#define MenuButton_h

#include "SDLGameObject.h"
//#include "GameObjectFactory.h"

class MenuButton : public SDLGameObject
{
public:
    MenuButton(const LoaderParams* Params, void (*callback)());
    
    virtual void draw();
    virtual void update();
    virtual void clean(){}
    /*virtual void load(const LoaderParams* Params);
    void setCallBack(void(*callback)()) { mCallback = callback; }
    int getCallBackID() { return mCallBackID; }*/
    
private:
    enum buttonState{
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
    };
    
    void (*OnClickEvent) ();
    
    bool released;
    /*void(*mCallback)();
    int mCallBackID;*/
    
};

/*class MenuButtonCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new MenuButton();
    }
};*/

#endif /* MenuButton_h */
