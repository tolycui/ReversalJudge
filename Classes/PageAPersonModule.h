#pragma once
#include "SystemHead.h"
#include "PersonHead.h"
class PageAPersonModule :
	public Sprite
{
public:
	PageAPersonModule();
	virtual ~PageAPersonModule();
	CREATE_FUNC(PageAPersonModule);
	bool init();
	Rect getHeadPicBoundingBox();
	Rect getNameBoundingBox();
	Rect getTextBoundingBox();
	void changeName(std::string str);
	void changeText(std::string str);
protected:
	PersonHead* personHead;
	Label* name;
	Label* text;
};

