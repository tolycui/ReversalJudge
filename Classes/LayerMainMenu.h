#pragma once
#include "LayerTopbarBasics.h"
#include "BottomBar.h"
class LayerMainMenu :
	public LayerTopbarBasics
{
public:
	LayerMainMenu();
	virtual ~LayerMainMenu();
	CREATE_FUNC(LayerMainMenu);
	bool init();
	BottomBar * getBottomBar(){ return bottomBar; }
	bool Myclicked(Ref* pSender);
protected:
	BottomBar *bottomBar;
	/*
	if clicked changed ,return true; otherwise return false;
	*/

};

