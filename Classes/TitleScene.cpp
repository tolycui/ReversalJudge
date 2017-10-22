#include "TitleScene.h"
#include "cocostudio/CocoStudio.h"


#include "SceneManage.h"


USING_NS_CC;

TitleScene::~TitleScene()
{
	removeAllChildrenWithCleanup(true);
	CC_SAFE_RELEASE(this->PGameProgress);
}

Scene* TitleScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TitleScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
//在init做异步纹理加载,此前先判断当前运行到哪个游戏进程;用UserDefault保存游戏进程,将游戏进程传递给游戏管理场景
bool TitleScene::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	//bgPic
	auto spr = Sprite::create("TitleSceneBgPic.jpg");
	spr->setAnchorPoint(Vec2(0.5, 0.5));
	spr->setPosition(Vec2(designResolutionSize.width / 2, designResolutionSize.height / 2));
	addChild(spr);

	//titlePic
	auto titlespr = Sprite::create("Title.png");
	titlespr->setPosition(Vec2(designResolutionSize.width / 2, designResolutionSize.height / 8 * 7));
	titlespr->setAnchorPoint(Vec2(0.5, 1));
	addChild(titlespr);
	Dictionary* message = CCDictionary::createWithContentsOfFile("chinesexml/chinese.xml");    //读取xml文件，文件在Resources目录下
	auto helpTitleKey = message->valueForKey("zhizuoren");    //根据key，获取value
	const char* helpTitle = helpTitleKey->getCString();    //将value转化为字符串
	//text
	auto label1 = Label::createWithBMFont("fnt/Myfnt.fnt", helpTitle);

	auto helpTitleKey2 = message->valueForKey("cehua");    //根据key，获取value
	const char* helpTitle2 = helpTitleKey2->getCString();    //将value转化为字符串
	auto label2 = Label::createWithBMFont("fnt/Myfnt.fnt", helpTitle2);

	auto helpTitleKey3 = message->valueForKey("chengxu");    //根据key，获取value
	const char* helpTitle3 = helpTitleKey3->getCString();    //将value转化为字符串
	auto label3 = Label::createWithBMFont("fnt/Myfnt.fnt", helpTitle3);

	label1->setColor(Color3B::YELLOW);  //BMFont字体这样设置颜色;
	label2->setColor(Color3B::YELLOW);
	label3->setColor(Color3B::YELLOW);
	label1->setAnchorPoint(Vec2(0, 1));
	label2->setAnchorPoint(Vec2(0, 1));
	label3->setAnchorPoint(Vec2(0, 1));
	label1->setPosition(Vec2(30, 300));
	label2->setPosition(Vec2(30, 240));
	label3->setPosition(Vec2(30, 180));
	addChild(label1);
	addChild(label2);
	addChild(label3);

	//读取存档文件,根据index读取csv文件,生成GameProgress类;
	std::string writePath = FileUtils::getInstance()->getWritablePath();
	log("%s",writePath);
	int Index = UserDefault::getInstance()->getIntegerForKey("Index");
	if (Index == 0)
	{
		Index = 1;
		UserDefault::getInstance()->setIntegerForKey("Index", Index);
	}

	PGameProgress = MyUtils::getInstence()->createProgressNow(Index);
	PGameProgress->retain();

	//设置触摸
	EventListenerTouchOneByOne *touchOne = EventListenerTouchOneByOne::create();
	touchOne->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchOne,this);
	//设置游戏管理类;
	SceneManage::getInstance();
	return true;
}

void TitleScene::SceneGameSelect(float dt)
{

}



bool TitleScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	log("touch");
	EventCustom _changeScene = EventCustom("changeScene");
	_changeScene.setUserData(PGameProgress);
	_eventDispatcher->dispatchEvent(&_changeScene);
	return false;
}


