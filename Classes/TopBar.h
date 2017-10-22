#pragma once
#include "SystemHead.h"
#include "BottomBar.h"


class TopBar :public Node
{
public:
	~TopBar();
	CREATE_FUNC(TopBar);
	bool init();
	Label * label;
	Sprite * TopBarFrame;
	//void changeText(std::string text);
};
