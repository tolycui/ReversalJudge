#pragma once
#include "SystemHead.h"
#include "LayerMainMenu.h"

class BottomBar;

class SceneMain :public cocos2d::Layer
{
public:
	SceneMain();
	~SceneMain();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(SceneMain);
	bool init();
	void onEnter()override;
	void Myclicked(Ref * pSender);
	//void MyclickedB(Ref * pSender);
	//void MyclickedC(Ref * pSender);
	//void MyclickedD(Ref * pSender);
protected:
	LayerMainMenu * layerMainMenu;

};

