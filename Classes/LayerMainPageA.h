#pragma once
#include "SystemHead.h"
#include "PageAPersonModule.h"

class LayerMainPageA :
	public Layer
{
public:
	LayerMainPageA();
	virtual ~LayerMainPageA();
	CREATE_FUNC(LayerMainPageA);
	bool init();
protected:
	PageAPersonModule * moduleOwn;
};

