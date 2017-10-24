#include "LayerMainPageA.h"


LayerMainPageA::LayerMainPageA()
{
}


LayerMainPageA::~LayerMainPageA()
{
	removeAllChildren();
}

bool LayerMainPageA::init()
{
	if (!Layer::init())
	{
		return false;
	}
	this->setZOrder(1);
	moduleOwn = PageAPersonModule::create();
	addChild(moduleOwn);

	return true;
}
