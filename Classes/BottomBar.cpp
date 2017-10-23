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
	__Dictionary* message = __Dictionary::createWithContentsOfFile(CHINESE_XML);    //read xml
	std::string str;
	Label*aLabel;

	for (int i = 1; i <= 4; i++)
	{
		String* filename = (String::createWithFormat("BottomItem%d", i));
		filename->append(PIC);
		MenuItemImage *  aMenuItem = MenuItemImage::create(filename->getCString(), filename->getCString());
		aMenuItem->setScale(WID / aMenuItem->getContentSize().width);
		aMenuItem->setTag(BarItemTag[i-1]);
		aMenuItem->setName(BarItemNameVec[0]);
		aMenuItem->setAnchorPoint(Vec2(0, 0));
		aMenuItem->setPosition(Vec2(WID*(1 + (i - 1) * 3), BOTTOMBARTEXT));  //bottombar  bottom keep 1/3 to place text;
		aMenuItem->setCascadeColorEnabled(true);

		str = message->valueForKey(barName[i-1])->getCString();
		aLabel = Label::createWithBMFont(CHINESE_FNT, str, TextHAlignment::CENTER);
		aLabel->setBMFontSize(28);
		aLabel->setAnchorPoint(Vec2(0.5, 1));
		aMenuItem->addChild(aLabel);
		aLabel->setName("text");
		aLabel->setPosition(Vec2(aLabel->getParent()->getContentSize().width / 2, DISTC_T_I));

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

	return true;
}


void BottomBar::setNowHL(MenuItem* item)
{
	item->setName(BarItemNameVec[1]);
	item->setColor(Color3B::ORANGE);
}

void BottomBar::setPreviouGray(MenuItem* itemPreHL)
{
	itemPreHL->setName(BarItemNameVec[0]);
	itemPreHL->setColor(Color3B::WHITE);
}

//clicked changed
void BottomBar::clickedSetHL(MenuItem* item)
{
	auto itemPre = (MenuItem*)getChildByName(BarItemNameVec[1]);
	setPreviouGray(itemPre);
	setNowHL(item);
}

void BottomBar::Myclicked(Ref * pSender)
{
	log("clicked");
	auto itemClicked = (MenuItem*)pSender;
	clickedSetHL(itemClicked);
}