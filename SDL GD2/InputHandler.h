#ifndef InputHandler_h
#define InputHandler_h

#include "SDL2/SDL.h"
#include <vector>
#include "Vector2D.h"

enum MouseButtons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};



class InputHandler
{
public:
    
    static InputHandler* Instance()
    {
        if(instance == 0)
        {
            instance = new InputHandler();
            return instance;
        }
        return instance;
    }
    
    bool getMouseButtonState(int buttonNumber);
    
    Vector2D* getMousePosition();
    
    bool isKeyDown(SDL_Scancode key);
    
    void clean(){}
    void update();
    
private:
    
    InputHandler();
    ~InputHandler(){}
    
    static InputHandler* instance;
           
    Uint8* mKeystates;
    
    void onMouseMove(SDL_Event &event);
    void onMouseButtonDown(SDL_Event &event);
    void onMouseButtonUp(SDL_Event &event);
    
    void onKeyDown();
    void onKeyUp();
    
    std::vector<bool> mouseButtonStates;
    Vector2D *mousePosition;
};

typedef InputHandler TheInputHandler;

#endif /* InputHandler_h */
