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

bool LayerMainMenu::Myclicked(Ref* pSender)
{
	//HL not change
	if (pSender == this->bottomBar->getChildByName(BarItemNameVec[1]))
	{
		return false;
	}
	//HL change
	MenuItem* itemClicked = dynamic_cast<MenuItem*>(pSender);
	Label * label = dynamic_cast<Label*> (itemClicked->getChildByName("text"));
	//change HL and change Text;
	this->bottomBar->Myclicked(pSender);
	this->topBar->changeText(label->getString());
	return true;
}