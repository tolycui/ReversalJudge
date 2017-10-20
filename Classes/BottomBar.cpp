#include "BottomBar.h"


BottomBar::BottomBar()
{
}


BottomBar::~BottomBar()
{
}

bool BottomBar::init()
{
	
	this->alignItemsHorizontally();
	return true;
}

BottomBar* BottomBar::create()
{
	Vector<MenuItem*> borromMenuVec;

	for (int i = 1; i <= 4; i++)
	{
		String* filename = String::createWithFormat("BottomItem+%d+.jpg", i);
		MenuItemImage *  aMenuItem = MenuItemImage::create(filename->getCString(), filename->getCString());
	/*	aMenuItem->setTag(GRAY);  
		aMenuItem->setName(stringVec[i - 1]);*/
		borromMenuVec.pushBack(aMenuItem);
	}
	BottomBar* bottombar = (BottomBar*)Menu::create(borromMenuVec.at(0), borromMenuVec.at(1), nullptr);
	bottombar->init();
	return bottombar;
}


void BottomBar::setNowHL(std::string itemName)
{

}

void BottomBar::setPreviouGray()
{

}

void BottomBar::setAnotherHL()
{

}
