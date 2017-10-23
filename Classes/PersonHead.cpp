#include "PersonHead.h"



PersonHead::~PersonHead()
{
	removeAllChildren();
}

PersonHead* PersonHead::create(std::string picPath, int diameter)
{
	PersonHead*personHead = new PersonHead();
	if (personHead&&personHead->init(picPath, diameter))
	{
		personHead->autorelease();
		return personHead;
	}
	CC_SAFE_DELETE(personHead);
	return personHead;
}

bool PersonHead::init(std::string picPath, int diameter)
{
	if (!Sprite::init())
	{
		return false;
	}
	setImg(picPath,diameter);
	return true;
}

/*
设置相关图片，返回设置好后的精灵
@param imgPath:头像图片路径
@param maskPath:模板图片路径
@param circlePath:边框路径
*/
void PersonHead::setImg(std::string picPath, int diameter)
{
	auto clipNode = ClippingNode::create();
	clipNode->autorelease();
	//mask scale
	auto mask = Sprite::create("red.png");
	mask->setScale(diameter / mask->getContentSize().height);
	mask->setContentSize(mask->getContentSize()*((float)diameter / mask->getContentSize().height));
	//set Node contentSize
	clipNode->setAlphaThreshold(0.0f);
	clipNode->setStencil(mask);

	//img scale
	auto img = Sprite::create(picPath);
	//将头像大小缩放为模板大小  

	img->setScale(diameter / img->getContentSize().height);
	log("%g", img->getContentSize().height);
	img->setContentSize(img->getContentSize()*((float)diameter / img->getContentSize().height));
	log("%g", img->getContentSize().height);
	clipNode->addChild(img);
	this->addChild(clipNode);
	//log("%g,%g", clipNode->getContentSize().width, clipNode->getContentSize().height);
	//add frame;
	auto circle = Sprite::create("headFrame.png");
	circle->setScale(diameter / circle->getContentSize().height);
	circle->setContentSize(circle->getContentSize()*((float)diameter / circle->getContentSize().height));

	this->setContentSize(mask->getContentSize());
	
	this->addChild(circle);
}


