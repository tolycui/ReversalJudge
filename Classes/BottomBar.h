#pragma once
#include "SystemHead.h"
#include "ui/CocosGUI.h"

using namespace ui;
static std::string barName[4] = { "xinxi", "tuili", "konggao", "sheding" };

enum EnumBarHL
{
	GRAY=0,
	HL=1,
};

static std::string BarItemNameVec[] = { "G","H"}; //G:gray  H:HL
static int BarItemTag[] = { 0, 1, 2, 3 };

class BottomBar :public Menu
{
public:
	BottomBar();
	~BottomBar();
	CREATE_FUNC(BottomBar);
	bool init();

	//Vector<MenuItemImage*> borromMenuVec;
	//Highlight when you click on another item
	void clickedSetHL(MenuItem* item);
	//4 page's callback ptr; 
	void Myclicked(Ref * pSender);

protected:
	
	void setNowHL(MenuItem* item); 
	void setPreviouGray(MenuItem* item);

};

