#include <stdio.h>
#include "SDL2/SDL.h"
//#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* Params) : SDLGameObject(Params)
{
    
}

void AnimatedGraphic::draw()
{
    SDLGameObject::draw();
}

void AnimatedGraphic::update()
{
    mCurrentFrame = int(SDL_GetTicks() / (1000 / animateSpeed) % 2);
}

/*void AnimatedGraphic::load(const LoaderParams* Params)
{
    SDLGameObject::load(Params);
    animateSpeed = Params->getAnimSpeed();
}*/
