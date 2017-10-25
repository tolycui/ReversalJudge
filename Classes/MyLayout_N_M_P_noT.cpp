#include "MyLayout_N_M_P_noT.h"


MyLayout_N_M_P_noT::MyLayout_N_M_P_noT()
{
}


MyLayout_N_M_P_noT::~MyLayout_N_M_P_noT()
{
	removeAllChildren();
}

void MyLayout_N_M_P_noT::setHeadPosition_my(Vec2 vec)
{
	this->personHead->setPosition(vec);
}

MyLayout_N_M_P_noT* MyLayout_N_M_P_noT::create(std::string name, std::string motto, std::string headFile, int diameter, float width, float height)
{
	MyLayout_N_M_P_noT * ly = new MyLayout_N_M_P_noT();
	if (ly&&ly->init(name, motto, headFile, diameter, width, height))
	{
		ly->autorelease();
		return ly;
	}
	CC_SAFE_DELETE(ly);
	return ly;
}

bool MyLayout_N_M_P_noT::init(std::string name, std::string motto, std::string headFile, int diameter, float width, float height)
{
	if (!MyLayout_N_M::init(name, motto, width, height))
	{
		return false;
	}

	this->personHead = PersonHead::create(headFile, diameter);
	addChild(personHead);
	return true;
}

Rect MyLayout_N_M_P_noT::getHeadBoundingBox()
{
	return this->personHead->getBoundingBox();
}
