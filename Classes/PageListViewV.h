#pragma once
#include "SystemHead.h"
#include "ui/CocosGUI.h"
using namespace ui;
class PageListViewV :public ListView
{
public:
	PageListViewV();
	~PageListViewV();
	CREATE_FUNC(PageListViewV);
	bool init();
	Layout* getLayoutByName();
protected:
	Vector<Layout*> LayerVec;
	/*
	给Layout设置Name的标记
	*/
	void setLayoutName(std::string name);

};

