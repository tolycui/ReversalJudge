#pragma once
#include "SystemHead.h"
#include "BottomBar.h"

class SceneMain :
	public Layer
{
public:
	SceneMain();
	~SceneMain();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(SceneMain);
	bool init();
	void onEnter();
protected:
	BottomBar * bottomBar;
};

