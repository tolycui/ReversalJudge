#pragma once
#include "SystemHead.h"
#include "TopBar.h"
class LayerTopbarBasics :
	public Layer
{
public:
	LayerTopbarBasics();
	virtual ~LayerTopbarBasics();
	CREATE_FUNC(LayerTopbarBasics);
	bool init();
protected:
	TopBar * topBar;
};

