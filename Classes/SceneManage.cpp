#include "SceneManage.h"
#include "ScreenBlink.h"
#include "FactoryScene.h"
SceneManage *SceneManage::_gInstance=nullptr;



//GameSceneManage* GameSceneManage::create(GameProgress* gameProg)
//{
//	GameSceneManage* manage = new GameSceneManage();
//	if (manage->init(gameProg))
//	{
//		manage->autorelease();
//		return manage;
//	}
//	CC_SAFE_RELEASE_NULL(manage);
//	return manage;
//	
//}

//bool GameSceneManage::init(GameProgress* gameProg)
//{
//	if (!Layer::init())
//	{
//		return false;
//	}
//	this->gameProg = gameProg;
//	this->gameProg->retain();
//	// 根据场景不同和index不同进入不同的场景分发;
//	switch (gameProg->get_ProgressType())
//	{
//	case progTypeEnum::Lines:
//	{
//		break;
//	}
//	case progTypeEnum::LinesSelect:
//	{
//		break;
//	}
//	case progTypeEnum::PropsSelect:
//	{
//		break;
//	}
//	case progTypeEnum::ExhibitSelect:
//	{
//		break;
//	}
//	case progTypeEnum::WitnessSelect:
//	{
//		break;
//	}
//	}
//	
//	return true;
//}

bool SceneManage::init()
{
	bool bRet = false;
	do
	{
		registerChangeSceneEvent();

		bRet = true;
	} while (0);
	return bRet;
}

void SceneManage::registerChangeSceneEvent()
{
	auto _eventDispatche = Director::getInstance()->getEventDispatcher();
	_eventDispatche->addCustomEventListener("changeScene", CC_CALLBACK_1(SceneManage::receiveChangeScene, this));
}

void SceneManage::changeScene(GameProgress* UserData)
{
	log("changeSceng");
	Scene * sc = FactoryScene::createScene(UserData->get_SceneType());
	Director::getInstance()->replaceScene(sc);
}

void SceneManage::initBlinkScene()
{
	// create a scene. it's an autorelease object
	auto scene = ScreenBlink::createScene();

	// run
	Director::getInstance()->runWithScene(scene);
}

void SceneManage::receiveChangeScene(EventCustom* event)
{

	GameProgress* UserData = reinterpret_cast<GameProgress*>(event->getUserData());
	changeScene(UserData);
}




