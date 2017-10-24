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
	if (!Sprite::initWithFile("BottomItem3.jpg"))
	{
		return false;
	}
	setImg(picPath, diameter);
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
	//mask scale
	auto mask = Sprite::create("red.png");
	mask->retain();//新加的


	float maskscale = diameter / mask->getContentSize().height;
	mask->setScale(diameter / mask->getContentSize().height);
	mask->setContentSize(mask->getContentSize()*maskscale);

	//仿射坐标映射
	AffineTransform transform = AffineTransform::IDENTITY;
	transform = AffineTransformScale(transform, mask->getScale(), mask->getScale());
	clipNode->setContentSize(SizeApplyAffineTransform(mask->getContentSize(), transform));



	//set Node contentSize  mask的锚点是0.5,0.5,初始位置是0,0
	clipNode->setAlphaThreshold(0.0f);
	clipNode->setStencil(mask);

	//log("mask %g,%g", mask->getPosition().x, mask->getPosition().y);
	//log("mask anch %g,%g", mask->getAnchorPoint().x, mask->getAnchorPoint().y);
	log("mask contentSize %g,%g", mask->getContentSize().width, mask->getContentSize().height);
	this->addChild(mask);
	mask->setPosition(Vec2(0, 0));
	//img scale
	auto img = Sprite::create(picPath);
	//将头像大小缩放为模板大小  

	
		//log("%g", img->getContentSize().height);
		////img->setContentSize(img->getContentSize()*((float)diameter / img->getContentSize().height));
		//log("%g", img->getContentSize().height);
	img->setScale(diameter / img->getContentSize().height);


	img->setContentSize(SizeApplyAffineTransform(mask->getContentSize(), transform));



	mask->setPosition(clipNode->getContentSize().width / 2, clipNode->getContentSize().height / 2);
	img->setPosition(clipNode->getContentSize().width / 2, clipNode->getContentSize().height / 2);
	clipNode->addChild(img);

	//log("%g,%g", clipNode->getContentSize().width, clipNode->getContentSize().height);
	//add frame;
	auto circle = Sprite::create("headFrame.png");
	circle->setScale(diameter / circle->getContentSize().height);
	//circle->setContentSize(circle->getContentSize()*((float)diameter / circle->getContentSize().height));
	circle->setContentSize(SizeApplyAffineTransform(mask->getContentSize(), transform));
	
	//this->setContentSize(SizeApplyAffineTransform(mask->getContentSize(), transform));

	//this->setContentSize(mask->getContentSize());
	circle->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
	clipNode->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
	this->addChild(clipNode);
	this->addChild(circle);
}


