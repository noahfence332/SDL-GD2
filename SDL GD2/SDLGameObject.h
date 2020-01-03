#ifndef SDLGameObject_h
#define SDLGameObject_h

#include <iostream>
#include "LoaderParams.h"
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
    
    SDLGameObject(const LoaderParams* Params);
    
    virtual void draw();
    virtual void drawFrame();
    virtual void update();
    virtual void clean();
    //virtual void load(const LoaderParams* Params);
    
    Vector2D& getPosition() { return mPosition; }
    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }
    //int getNumFrames() { return mNumFrames; }
    
protected:
    
    Vector2D mPosition;
    Vector2D mVelocity;
    Vector2D mAcceleration;
    
    int mWidth;
    int mHeight;
    int mCurrentRow;
    int mCurrentFrame;
    //int mNumFrames;
    
    std::string mTextureID;
};



#endif /* SDLGameObject_h */
