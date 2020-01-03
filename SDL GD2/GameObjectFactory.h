/*#ifndef GameObjectFactory_h
#define GameObjectFactory_h

#include <map>
#include "GameObject.h"

class BaseCreator
{
public:
    
    virtual GameObject *createGameObject() const = 0;
    virtual ~BaseCreator(){}
};

class GameObjectFactory
{
public:
    
    bool registerType(std::string typeID, BaseCreator *pCreator);
    GameObject* create(std::string typeID);
    
    static GameObjectFactory* Instance()
    {
        if(instance == 0)
        {
            instance = new GameObjectFactory();
            return instance;
        }
        return instance;
    }
    
private:
    std::map<std::string, BaseCreator*> mCreators;
    static GameObjectFactory *instance;
};

typedef GameObjectFactory TheGameObjectFactory;
#endif */ /* GameObjectFactory_h */

