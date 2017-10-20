#include "ScreenBlink.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MyUtils.h"
#include "TitleScene.h"



using namespace cocostudio::timeline;

Scene* ScreenBlink::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ScreenBlink::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ScreenBlink::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto spr = Sprite::create("ScreenBlinkBg.png");
	addChild(spr);
	spr->setPosition(Vec2(designResolutionSize.width / 2, designResolutionSize.height / 2));
	auto ac = FadeIn::create(0.1f);
	auto ac2 = FadeOut::create(0.1f);
	auto ac3 = CallFunc::create(CC_CALLBACK_0(ScreenBlink::GoToTitleScene,this));
	auto action = Sequence::create(ac, ac2, ac3,nullptr);
	spr->runAction(action);
	preLoadSource(PATH_CSV_OF_GAMEPROGRESS);
	/*scheduleOnce(schedule_selector(ScreenBlink::GoToTitleScene), 1);*/
	////解析xml
	//tinyxml2::XMLDocument *xmlDoc = new tinyxml2::XMLDocument();
	//MyUtils::getInstence()->ParseXML("xml/myxml.xml", xmlDoc);
	//auto root = xmlDoc->RootElement();
	////打印第一个节点的属性;
	//auto xmlEle = root->FirstChildElement();
	//auto attr = xmlEle->FirstAttribute();
	//log("weapon - %d", attr->IntValue());

	//if (xmlEle == nullptr)
	//{
	//	return false;
	//}
	//打印每个节点信息;
	//MyUtils::getInstence()->dumpXmlNode(xmlEle, "");
	//CC_SAFE_DELETE(xmlDoc);
	return true;
}



void ScreenBlink::GoToTitleScene()
{
	//TitleSceneBgPic.jpg
	Scene *sc = TitleScene::createScene();
	Director::getInstance()->replaceScene(sc);
}

ScreenBlink::~ScreenBlink()
{
	removeAllChildrenWithCleanup(true);
}

void ScreenBlink::preLoadSource(const std::string &  csvFilePatch)  //const std::string&表示常量字符串;
{
	auto csvUtil = CsvUtil::getInstance();
	csvUtil->addFileData(csvFilePatch);
}
