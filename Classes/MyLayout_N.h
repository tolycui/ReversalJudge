#pragma once
#include "SystemHead.h"
#include "ui/CocosGUI.h"
using namespace ui;

class MyLayout_N :public Layout
{
public:
	virtual ~MyLayout_N();

	/*
	可以设置默认值
	float width, float height :Layout的contentSize();
	*/
	static MyLayout_N*create(std::string name, float width, float height);

	bool init(std::string name, float width, float height);

	void setNamePosition_my(cocos2d::Vec2 fd);
	void setNameDimensions(float width, float height);


	/*
	点击文字框触发, 点击屏幕外修改生效;
	*/
	//void setName(std::string name);

	Rect getNameBoundingBox();
protected:
	CC_SYNTHESIZE(std::string, name, _Name);

	CC_SYNTHESIZE_READONLY(Label*, labelName, _LabelName);
};

