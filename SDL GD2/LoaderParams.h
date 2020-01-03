#ifndef LoaderParams_h
#define LoaderParams_h

#include <iostream>

class LoaderParams
{
public:
    
    LoaderParams(int x, int y, int width, int height, std::string textureID, int numFrames, int callbackID = 0, int animateSpeed = 0): mX(x), mY(y), mWidth(width), mHeight(height), mTextureID(textureID){}
    
    int getX() const { return mX;}
    int getY() const { return mY;}
    int getWidth() const { return mWidth;}
    int getHeight() const { return mHeight;}
    /*int getNumFrames() const { return mNumFrames; }
    int getAnimSpeed() const { return mAnimSpeed; }
    int getCallBackID() const { return mCallBackID; }*/
    
    std::string getTextureID() const { return mTextureID;}
    
private:
    
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    /*int mNumFrames;
    int mCallBackID;
    int mAnimSpeed;*/
    
    std::string mTextureID;
};

#endif /* LoaderParams_h */
