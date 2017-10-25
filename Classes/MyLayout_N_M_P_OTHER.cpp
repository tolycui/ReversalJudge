#include "MyLayout_N_M_P_OTHER.h"



MyLayout_N_M_P_OTHER::~MyLayout_N_M_P_OTHER()
{
	removeAllChildren();
	this->_eventDispatcher->removeCustomEventListeners("changeNameOther");
}

MyLayout_N_M_P_OTHER* MyLayout_N_M_P_OTHER::create(std::string name, std::string motto, std::string headFile, 
	int diameter /*= PERSONHEADHEIGHT_OTHER*/, float width /*= 100*/, float height/*=200*/)
{
	MyLayout_N_M_P_OTHER * ly = new MyLayout_N_M_P_OTHER();
	if (ly&&ly->init(name, motto, headFile, diameter, width, height))
	{
		ly->autorelease();
		return ly;
	}
	CC_SAFE_DELETE(ly);
	return ly;
}

bool MyLayout_N_M_P_OTHER::init(std::string name, std::string motto, std::string headFile,
	int diameter, float width, float height)
{
	if (!MyLayout_N_M_P_noT::init(name, motto, headFile, diameter,width, height))
	{
		return false;
	}
	//绑定一些触摸函数;
	this->_eventDispatcher->addCustomEventListener("changeNameOther", CC_CALLBACK_1(MyLayout_N_M_P_OTHER::changeName_Other,this));
	button = Button::create("botton.png", "botton_HL.png");
	button->setScale9Enabled(true);
	button->setScaleY(height / button->getContentSize().height);
	button->setScaleX(width / button->getContentSize().width);
	//bt->setContentSize(Size(size.width / 2, size.height / 2));
	button->setPosition(Point(width / 2, height / 2));
	addChild(button);
	button->addTouchEventListener(CC_CALLBACK_2(MyLayout_N_M_P_OTHER::MyClicked, this));
	this->get_personHead()->setZOrder(10);
	this->get_LabelName()->setZOrder(10);
	this->get_LabelMotto()->setZOrder(10);
	this->get_LabelName()->setColor(Color3B::BLACK);
	this->get_LabelMotto()->setColor(Color3B::BLACK);
	return true;

	auto layer = Layer::create();
	
}

void MyLayout_N_M_P_OTHER::changeName_Other(Ref* pData)
{
	if (this==pData)
	{
		log("changeNage_other");
		//要弹出一个层,并且这个层要将触摸优先级夺走;//好像也不对, 明天再研究一下触摸事件的优先级,父类是不是一定比子类来的
		EventListenerTouchOneByOne*test = EventListenerTouchOneByOne::create();
		_eventDispatcher->addEventListenerWithFixedPriority(test, -128);
		this->setSwallowTouches(true);
	}
}

//bool MyLayout_N_M_P_OTHER::onTouchBegan(Touch *touch, Event *unusedEvent)
//{
//	scheduleOnce(schedule_selector(MyLayout_N_M_P_OTHER::showLayoutChangeName),0.5f);
//	return false;
//}
//
//void MyLayout_N_M_P_OTHER::onTouchMoved(Touch *touch, Event *unusedEvent)
//{
//
//}
//
//void MyLayout_N_M_P_OTHER::onTouchEnded(Touch *touch, Event *unusedEvent)
//{
//
//}
//
//void MyLayout_N_M_P_OTHER::onTouchCancelled(Touch *touch, Event *unusedEvent)
//{
//
//}

//进入对话界面;要去网上找现成的代码;
void MyLayout_N_M_P_OTHER::EnterDialog()
{
	log("enterDialog");
	
	
}

void MyLayout_N_M_P_OTHER::showLayoutChangeName(float dt)
{
	log("showLayoutChangeName");
	EventCustom ev = EventCustom("changeNameOther");
	ev.setUserData(this);
	this->_eventDispatcher->dispatchEvent(&ev);  //每一个订阅者都收到消息;  不想让每一个订阅者都收到;
	
}

void MyLayout_N_M_P_OTHER::MyClicked(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
	{

		scheduleOnce(schedule_selector(MyLayout_N_M_P_OTHER::showLayoutChangeName), 0.5f);
		log("begin");
		break;
	}
	case cocos2d::ui::Widget::TouchEventType::MOVED:
	{
		unschedule(schedule_selector(MyLayout_N_M_P_OTHER::showLayoutChangeName));
		log("moved");
		break;
	}
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
	case cocos2d::ui::Widget::TouchEventType::ENDED:
	{

		log("ended");
		break;
	}
	}
}
