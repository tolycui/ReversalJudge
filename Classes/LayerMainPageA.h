#pragma once
#include "SystemHead.h"
#include "PageAPersonModule.h"
#include "PageADialogMudule.h"

class LayerMainPageA :
	public Layer
{
public:
	LayerMainPageA();
	virtual ~LayerMainPageA();
	CREATE_FUNC(LayerMainPageA);
	bool init();
	void showLayoutChangeNameOther(EventCustom* event);
	void RecoverListTouch(EventCustom* event);
protected:
	PageAPersonModule * moduleOwn;
	PageADialogMudule * dialog;

};

