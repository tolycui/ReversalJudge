#include "SceneMain.h"



SceneMain::SceneMain()
{

}



SceneMain::~SceneMain()
{
	removeAllChildren();
}


Scene* SceneMain::createScene()
{
	auto scene = Scene::create();
	auto layer = SceneMain::create();
	scene->addChild(layer);
	return scene;
}

void SceneMain::onEnter()
{
	Layer::onEnter();
}

bool SceneMain::init()
{
	if (!Layer::init())
	{
		return false;
	}
	layerMainMenu = LayerMainMenu::create();
	addChild(layerMainMenu);

	MenuItem * item;
	for (int i = 0; i < 4;i++)
	{
		item = dynamic_cast<MenuItem *>(this->layerMainMenu->getBottomBar()->getChildByTag(i));
		item->setCallback(CC_CALLBACK_1(SceneMain::Myclicked,this));
	}
	auto per1 = PersonHead::create("PersonagePic/name1.jpg", PERSONHEADHEIGHT_OWN);
	addChild(per1);
	per1->setPosition(Vec2(200, 200));

	layerBg = LayerBg::create(LAYER_PAGEA_BGPIC);
	addChild(layerBg);
	return true;
}

void SceneMain::Myclicked(Ref * pSender)
{
	log("A");
	//Menu text changed and color changed
	this->layerMainMenu->Myclicked(pSender);

}

void SceneMain::showLayerPageA()
{

}
void SceneMain::showLayerPageB()
{

}
void SceneMain::showLayerPageC()
{

}
void SceneMain::showLayerPageD()
{

}

void SceneMain::clickedBar()
{

}

