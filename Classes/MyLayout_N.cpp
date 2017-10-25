#include "MyLayout_N.h"



MyLayout_N::~MyLayout_N()
{
	removeAllChildren();
}





MyLayout_N* MyLayout_N::create(std::string name, float width, float height)
{
	MyLayout_N * ly = new MyLayout_N();
	if (ly&&ly->init(name,width,height))
	{
		ly->autorelease();
		return ly;
	}
	CC_SAFE_DELETE(ly);
	return ly;
}

bool MyLayout_N::init(std::string name, float width, float height)
{
	if (!Layout::init())
	{
		return false;
	}

	this->name = name;
	labelName = Label::createWithTTF(name, FNT1, 28.0);
	labelName->setLineBreakWithoutSpace(true);
	this->setContentSize(Size(width, height));
	addChild(labelName);

	this->labelName->setPosition(Vec2(10, 10));
	labelName->setDimensions(200, 100);

	return true;
}

void MyLayout_N::setNameDimensions(float width, float height)
{
	labelName->setDimensions(width, height);
}


//void MyLayoutOnlyName::setName(std::string name)
//{
//	int length = std::strlen(name.c_str());
//	if (length>16)
//	{
//		log("名字长度不能超过8个字");
//		return;
//	}
//	this->name = name;
//	labelName->setString(name);
//}

void MyLayout_N::setNamePosition_my(Vec2 fd)
{

	labelName->setPosition(fd);
}

Rect MyLayout_N::getNameBoundingBox()
{
	return labelName->getBoundingBox();
}

