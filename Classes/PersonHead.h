#pragma once
#include "SystemHead.h"
class PersonHead :public Sprite
{
public:
	virtual	~PersonHead();
	/*
	diameter: cicre's diameter
	*/
	static PersonHead* create(std::string picPath, int  diameter = PERSONHEADHEIGHT_OTHER);
	bool init(std::string picPath, int  diameter);
	void setImg(std::string picPath, int diameter);
};

