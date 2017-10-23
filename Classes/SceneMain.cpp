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

	//set clicked call back;
	//for (int i = 0; i < 4;i++)
	//{
	//	;
	//}
	

	return true;
}

void SceneMain::Myclicked(Ref * pSender)
{
	log("A");
	MenuItem* item = (MenuItem*)pSender;
	
	__Dictionary* message = __Dictionary::createWithContentsOfFile(CHINESE_XML);    //read xml
	std::string str = message->valueForKey(barName[0])->getCString();
	//topBar->changeText(str);
}

//void SceneMain::MyclickedB(Ref * pSender)
//{
//	log("b");
//	__Dictionary* message = __Dictionary::createWithContentsOfFile(CHINESE_XML);    //read xml
//	std::string str = message->valueForKey(barName[1])->getCString();
//	topBar->changeText(str);
//}
//void SceneMain::MyclickedC(Ref * pSender)
//{
//	log("c");
//	__Dictionary* message = __Dictionary::createWithContentsOfFile(CHINESE_XML);    //read xml
//	std::string str = message->valueForKey(barName[2])->getCString();
//	topBar->changeText(str);
//}
//void SceneMain::MyclickedD(Ref * pSender)
//{
//	log("d");
//	__Dictionary* message = __Dictionary::createWithContentsOfFile(CHINESE_XML);    //read xml
//	std::string str = message->valueForKey(barName[3])->getCString();
//	topBar->changeText(str);
//}