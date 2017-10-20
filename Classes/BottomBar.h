#pragma once
#include "D:\Cocos\Cocos2d-x\cocos2d-x-3.10\cocos\2d\CCNode.h"
#include "SystemHead.h"
#include "ui/CocosGUI.h"

using namespace ui;
enum EnumBarHL
{
	GRAY=0,
	HL=1,
};

static std::string stringVec[] = { "A","B","C","D" };
class BottomBar :
	public Menu
{
public:
	BottomBar();
	~BottomBar();
	static BottomBar* create();
	bool init();

	//Vector<MenuItemImage*> borromMenuVec;
	//Highlight when you click on another item
	void setAnotherHL();
protected:
	void setNowHL(std::string itemName); 
	void setPreviouGray();

};

