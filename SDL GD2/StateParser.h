#ifndef StateParser_h
#define StateParser_h
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "tinyxml.h"

class StateParser
{
public:
    
    bool parseState(const char* stateFile, std::string stateID, std::vector<GameObject*>*pObjects, std::vector<std::string>*pTextureIDs);
    
private:
    
    void parseObjects(TiXmlElement *pStateRoot, std::vector<GameObject*>*pObjects);
    void parseTextures(TiXmlElement *pStateRoot, std::vector<std::string>*pTextureIDs);
    
};



#endif /* StateParser_h */
