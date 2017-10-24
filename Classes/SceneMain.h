#pragma once
#include "SystemHead.h"
#include "LayerMainMenu.h"
#include "PersonHead.h"
#include "LayerBg.h"
#include "LayerMainPageA.h"
#include "LayerMainPageB.h"
#include "LayerMainPageC.h"
#include "LayerMainPageD.h"

class BottomBar;

class SceneMain :public cocos2d::Layer
{
public:
	SceneMain();
	virtual~SceneMain();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(SceneMain);
	bool init();
	void onEnter()override;
	void Myclicked(Ref * pSender);

protected:
	LayerMainMenu * layerMainMenu;
	LayerBg * layerBg;
	LayerMainPageA * pageA;

	void clickedBar();
	void showLayerPageA();
	void showLayerPageB();
	void showLayerPageC();
	void showLayerPageD();
};

