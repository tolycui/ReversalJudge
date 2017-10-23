#include "TopBar.h"

TopBar::~TopBar()
{
	removeAllChildren();
}

bool TopBar::init()
{
	if (!Node::init())
	{
		return false;
	}
	std::string fileName = "BottomBarFrame";
	fileName.append(PIC);
	TopBarFrame = Sprite::create(fileName);
	TopBarFrame->setAnchorPoint(Vec2(0, 0));
	TopBarFrame->setPosition(Vec2(0, 0));
	TopBarFrame->setZOrder(-1);
	this->addChild(TopBarFrame);

	this->setContentSize(TopBarFrame->getContentSize());

	__Dictionary* message = __Dictionary::createWithContentsOfFile(CHINESE_XML);
	std::string str = message->valueForKey(barName[0])->getCString();
	label = Label::createWithBMFont(CHINESE_FNT, str, TextHAlignment::CENTER);
	label->setBMFontSize(36);
	label->setPosition(Vec2(FRAMESIZE.width / 2, this->getContentSize().height / 2));
	this->addChild(label);

	this->setAnchorPoint(Vec2(0, 1));
	this->setPosition(Vec2(0, FRAMESIZE.height));
	return true;
}


void TopBar::changeText(std::string text)
{
	this->label->setString(text);
}
