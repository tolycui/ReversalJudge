#include "LayerBg.h"


LayerBg::LayerBg()
{
}


LayerBg::~LayerBg()
{
	removeAllChildren();
}

LayerBg* LayerBg::create(std::string filePath)
{
	LayerBg* bg = new LayerBg();
	if (bg&&bg->init(filePath))
	{
		bg->autorelease();
		return bg;
	}
	CC_SAFE_DELETE(bg);
	return bg;
}

bool LayerBg::init(std::string filePath)
{
	if (!Layer::init())
	{
		return false;
	}
	Sprite * bg = Sprite::create(filePath);
	bg->setPosition(Vec2(FRAMESIZE.width / 2, FRAMESIZE.height / 2));
	addChild(bg);
	this->setZOrder(-1);
	return true;
}
