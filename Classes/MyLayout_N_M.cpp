#include "MyLayout_N_M.h"

MyLayout_N_M::~MyLayout_N_M()
{
	removeAllChildren();
}

void MyLayout_N_M::setMottoPosition_my(Vec2 vec)
{
	this->labelMotto->setPosition(vec);
}

MyLayout_N_M* MyLayout_N_M::create(std::string name, std::string motto, float width, float height)
{
	MyLayout_N_M * ly = new MyLayout_N_M();
	if (ly&&ly->init(name, motto, width, height))
	{
		ly->autorelease();
		return ly;
	}
	CC_SAFE_DELETE(ly);
	return ly;
}

bool MyLayout_N_M::init(std::string name, std::string motto, float width, float height)
{
	if (!MyLayout_N::init(name,width,height))
	{
		return false;
	}
	this->motto = motto;
	labelMotto = Label::createWithTTF(motto, FNT1, 28.0);
	labelMotto->setLineBreakWithoutSpace(true);
	labelMotto->setHorizontalAlignment(TextHAlignment::LEFT);
	labelMotto->setAnchorPoint(Vec2(0, 1));
	addChild(labelMotto);
	return true;
}

void MyLayout_N_M::setMottoDimensions(float width, float height)
{
	labelMotto->setDimensions(width, height);
}

Rect MyLayout_N_M::getmottoBoundingBox()
{
	return this->labelMotto->getBoundingBox();
}
