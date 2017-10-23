#include "LayerTopbarBasics.h"


LayerTopbarBasics::LayerTopbarBasics()
{
}


LayerTopbarBasics::~LayerTopbarBasics()
{
	removeAllChildren();
}

bool LayerTopbarBasics::init()
{
	if (!Layer::init())
	{
		return false;
	}
	topBar = TopBar::create();
	topBar->setAnchorPoint(Vec2(0, 1));
	topBar->setPosition(Vec2(0, FRAMESIZE.height));
	addChild(topBar);

	return true;
}
