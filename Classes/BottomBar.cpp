#include "BottomBar.h"
#include "SceneMain.h"

#define DISTC_T_I -4   //distance of text and image

BottomBar::BottomBar()
{
}


BottomBar::~BottomBar()
{
}

bool BottomBar::init()
{
	//set bottom bar item and callback;

	Vector<MenuItem*> borromMenuVec;
	for (int i = 1; i <= 4; i++)
	{
		String* filename = (String::createWithFormat("BottomItem%d", i));
		filename->append(PIC);
		MenuItemImage *  aMenuItem = MenuItemImage::create(filename->getCString(), filename->getCString());
		aMenuItem->setScale(WID / aMenuItem->getContentSize().width);
		aMenuItem->setTag(EnumBarHL::GRAY);
		aMenuItem->setName(BarItemNameVec[i - 1]);
		aMenuItem->setAnchorPoint(Vec2(0, 0));
		aMenuItem->setPosition(Vec2(WID*(1 + (i - 1) * 3), BOTTOMBARTEXT));  //bottombar  bottom keep 1/3 to place text;
		aMenuItem->setCascadeColorEnabled(true);
		borromMenuVec.pushBack(aMenuItem);
	}
	if (!Menu::initWithArray(borromMenuVec))
	{
		return	false;
	}
	setNowHL(borromMenuVec.at(0));
	ignoreAnchorPointForPosition(false);
	setAnchorPoint(Vec2(0, 0));
	setPosition(Vec2(0, 0));

	//xinxi tuili konggao sheding
	__Dictionary* message = __Dictionary::createWithContentsOfFile(CHINESE_XML);    //read xml
	std::string str = message->valueForKey(barName[0])->getCString();
	auto aLabel = Label::createWithBMFont(CHINESE_FNT, str, TextHAlignment::CENTER);
	aLabel->setBMFontSize(28);
	aLabel->setAnchorPoint(Vec2(0.5, 1));
	borromMenuVec.at(0)->addChild(aLabel);
	aLabel->setPosition(Vec2(aLabel->getParent()->getContentSize().width / 2, DISTC_T_I));

	str = message->valueForKey(barName[1])->getCString();
	aLabel = Label::createWithBMFont(CHINESE_FNT, str, TextHAlignment::CENTER);
	aLabel->setBMFontSize(28);
	aLabel->setAnchorPoint(Vec2(0.5, 1));
	borromMenuVec.at(1)->addChild(aLabel);
	aLabel->setPosition(Vec2(aLabel->getParent()->getContentSize().width / 2, DISTC_T_I));

	str = message->valueForKey(barName[2])->getCString();
	aLabel = Label::createWithBMFont(CHINESE_FNT, str, TextHAlignment::CENTER);
	aLabel->setBMFontSize(28);
	aLabel->setAnchorPoint(Vec2(0.5, 1));
	borromMenuVec.at(2)->addChild(aLabel);
	aLabel->setPosition(Vec2(aLabel->getParent()->getContentSize().width / 2, DISTC_T_I));

	str = message->valueForKey(barName[3])->getCString();
	aLabel = Label::createWithBMFont(CHINESE_FNT, str, TextHAlignment::CENTER);
	aLabel->setBMFontSize(28);
	aLabel->setAnchorPoint(Vec2(0.5, 1));
	borromMenuVec.at(3)->addChild(aLabel);
	aLabel->setPosition(Vec2(aLabel->getParent()->getContentSize().width / 2, DISTC_T_I));

	return true;
}


void BottomBar::setNowHL(MenuItem* item)
{
	item->setTag(EnumBarHL::HL);
	item->setColor(Color3B::ORANGE);
}

void BottomBar::setPreviouGray(MenuItem* itemPreHL)
{
	itemPreHL->setTag(EnumBarHL::GRAY);
	itemPreHL->setColor(Color3B::WHITE);
}

void BottomBar::clickedSetHL(MenuItem* item)
{
	auto itemPre = (MenuItem*)getChildByTag(EnumBarHL::HL);
	if (itemPre == item)
	{
		return;
	}
	setPreviouGray(itemPre);
	setNowHL(item);
}

void BottomBar::Myclicked(Ref * pSender)
{
	log("clicked");
	auto itemClicked = (MenuItem*)pSender;
	clickedSetHL(itemClicked);
}

//void BottomBar::MyclickedB(Ref * pSender)
//{
//	log("B");
//	auto itemClicked = (MenuItem*)pSender;
//	clickedSetHL(itemClicked);
//}
//
//void BottomBar::MyclickedC(Ref * pSender)
//{
//	log("C");
//	auto itemClicked = (MenuItem*)pSender;
//	clickedSetHL(itemClicked);
//}
//
//void BottomBar::MyclickedD(Ref * pSender)
//{
//	log("D");
//	auto itemClicked = (MenuItem*)pSender;
//	clickedSetHL(itemClicked);	
//}