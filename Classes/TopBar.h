#pragma once
#include "SystemHead.h"
#include "BottomBar.h"


class TopBar :public Node
{
public:
	~TopBar();
	CREATE_FUNC(TopBar);
	bool init();
	void changeText(std::string text);
protected:
	Label * label;
	Sprite * TopBarFrame;
};
