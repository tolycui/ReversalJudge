//
//  publicConfig.h
//  newCardDefence
//
//  Created by Yan on 14-8-27.
//
//

#ifndef newCardDefence_publicDefine_h
#define newCardDefence_publicDefine_h


//#include "PublicSourceDefine.h"


#define CREATE_INSTANCE_FUNC(__CLASS__) \
private:\
    static __CLASS__ *_gInstance;\
public:\
static __CLASS__* getInstance()\
{\
    if(!_gInstance)\
    {\
        _gInstance = new __CLASS__();\
        if(_gInstance && _gInstance->init())\
        {\
            _gInstance->autorelease();\
            _gInstance->retain();\
        }\
        else\
        {\
            CC_SAFE_DELETE(_gInstance);\
        }\
    }\
    return _gInstance;\
}

#define DESTROY_INSTANCE_FUNC()\
static void destroyInstance()\
{\
    CC_SAFE_RELEASE_NULL(_gInstance);\
}


#endif
