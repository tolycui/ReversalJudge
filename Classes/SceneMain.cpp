#include "SceneMain.h"


SceneMain::SceneMain()
{
}


SceneMain::~SceneMain()
{
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

}

bool SceneMain::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto spr = Sprite::create("BottomItem3.jpg");
	spr->setPosition(Vec2(10, 100));
	spr->setAnchorPoint(Vec2(0, 0));
	addChild(spr);

	//Vector<MenuItem*> borromMenuVec;
	//for (int i = 1; i <= 4; i++)
	//{
	//	String* filename = String::createWithFormat("BottomItem3.jpg", i);
	//	MenuItemImage *  aMenuItem = MenuItemImage::create(filename->getCString(), filename->getCString());
	//	/*	aMenuItem->setTag(GRAY);
	//	aMenuItem->setName(stringVec[i - 1]);*/
	//	aMenuItem->setAnchorPoint(Vec2(0, 0));
	//	aMenuItem->setPosition(Vec2(50, 100 * i));
	//	borromMenuVec.pushBack(aMenuItem);
	//}
	//Menu *mn = Menu::createWithArray(borromMenuVec);
	//mn->alignItemsVertically();
	//mn->setAnchorPoint(Vec2(0, 0));
	//mn->setPosition(Vec2(0, 0));
	////mn->setContentSize(Size(FRAMESIZE.width / 2, FRAMESIZE.height / 2));
	//addChild(mn);

	//log("x=%g,y=%g", this->getContentSize().width, this->getContentSize().height);




	//bottomBar = BottomBar::create();
	//bottomBar->setPosition(Vec2(0, 0));
	//this->addChild(bottomBar);
	
	/*Sprite *bg = Sprite::create("MainSceneBg.jpg");
	bg->setZOrder(-99);
	addChild(bg);
	bg->setPosition(Vec2(FRAMESIZE.width / 2, FRAMESIZE.height / 2));*/

	return true;
}
