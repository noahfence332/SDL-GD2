/*#include <stdio.h>
#include "GameObjectFactory.h"
#include <string>

GameObjectFactory *GameObjectFactory::instance = 0;

GameObject *GameObjectFactory::create(std::string typeID)
{
    
    std::map<std::string, BaseCreator*>::iterator it = mCreators.find(typeID);
    
    if(it != mCreators.end())
    {
        BaseCreator* pCreator = (*it).second;
        return pCreator->createGameObject();
    }
    
    std::cout << "could not find type: " << typeID << std::endl;
    return nullptr;
}

bool GameObjectFactory::registerType(std::string typeID, BaseCreator * pCreator)
{
    std::map<std::string, BaseCreator*>::iterator it = mCreators.find(typeID);
    
    if(it != mCreators.end())
    {
        delete pCreator;
        return false;
    }
    
    mCreators[typeID] = pCreator;
    return true;
}*/
