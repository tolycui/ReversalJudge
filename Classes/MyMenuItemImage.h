#pragma once
#include "D:\Cocos\Cocos2d-x\cocos2d-x-3.10\cocos\2d\CCMenuItem.h"
#include "SystemHead.h"
class MyMenuItemImage :
	public MenuItemImage
{
public:
	MyMenuItemImage();
	~MyMenuItemImage();
	CREATE_FUNC(MyMenuItemImage);
	bool init();
	CC_SYNTHESIZE_PASS_BY_REF(bool, HLFlag, _HLFlag);
};

