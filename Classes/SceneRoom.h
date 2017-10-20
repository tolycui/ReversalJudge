#pragma once
#include "SystemHead.h"
class SceneRoom :
	public Layer
{
public:
	SceneRoom();
	~SceneRoom();
	static cocos2d::Scene* createScene();
};

