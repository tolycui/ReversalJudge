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
protected:
	BottomBar *bottomBar;

};

