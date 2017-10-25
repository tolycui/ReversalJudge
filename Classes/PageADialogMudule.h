#pragma once
#include "SystemHead.h"
#include "ui/CocosGUI.h"
using namespace ui;

//ListView 视图;
class PageADialogMudule :public ui::ListView
{
public:
	PageADialogMudule();
	~PageADialogMudule();
	CREATE_FUNC(PageADialogMudule);
	bool init();
protected:
	std::vector<std::string> _array;
};

