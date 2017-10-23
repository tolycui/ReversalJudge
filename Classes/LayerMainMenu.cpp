#include "LayerMainMenu.h"


LayerMainMenu::LayerMainMenu()
{
}


LayerMainMenu::~LayerMainMenu()
{
	removeAllChildren();
}

bool LayerMainMenu::init()
{
	if (!LayerTopbarBasics::init())
	{
		return false;
	}
	bottomBar = BottomBar::create();
	addChild(bottomBar);

	std::string fileName = "BottomBarFrame";
	fileName.append(PIC);
	auto bottomBarFrame = Sprite::create(fileName);
	bottomBarFrame->setAnchorPoint(Vec2(0, 0));
	bottomBarFrame->setPosition(Vec2(0, 0));
	bottomBarFrame->setZOrder(-1);
	addChild(bottomBarFrame);

	this->setPosition(Vec2(0, 0));
	return true;
}
