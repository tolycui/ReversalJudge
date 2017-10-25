#include "MyLayout_N_M_P_OTHER.h"



MyLayout_N_M_P_OTHER::~MyLayout_N_M_P_OTHER()
{
	removeAllChildren();
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
	if (!MyLayout_N_M::init(name, motto, width, height))
	{
		return false;
	}
	//绑定一些触摸函数;


	return true;
}

void MyLayout_N_M_P_OTHER::changeName_Other(Ref* pData)
{

}

bool MyLayout_N_M_P_OTHER::onTouchBegan(Touch *touch, Event *unusedEvent)
{

}

void MyLayout_N_M_P_OTHER::onTouchMoved(Touch *touch, Event *unusedEvent)
{

}

void MyLayout_N_M_P_OTHER::onTouchEnded(Touch *touch, Event *unusedEvent)
{

}

void MyLayout_N_M_P_OTHER::onTouchCancelled(Touch *touch, Event *unusedEvent)
{

}

void MyLayout_N_M_P_OTHER::EnterDialog()
{

}

void MyLayout_N_M_P_OTHER::showLayoutChangeName()
{

}
