#include <iostream>
#include "Game.h"

Game* game = nullptr;

int main(int argc, const char * argv[])
{
    std::cout << "game init attempt...\n";
    if(TheGame::Instance()->init("Platform World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TheGame::Instance()->SCREEN_WIDTH, TheGame::Instance()->SCREEN_HEIGHT, false))
    {
        std::cout << "game init success\n";
        TheGame::Instance()->run();
    }
    else
    {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
    }
    
    std::cout << "game closing...\n";
    TheGame::Instance()->clean();
    return 0;
}
