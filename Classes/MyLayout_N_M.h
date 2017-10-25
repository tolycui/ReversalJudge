#pragma once
#include "MyLayout_N.h"
#include "ui/CocosGUI.h"
using namespace ui;
/*
内容不可更改类型;人物说明,物件说明系列;
*/
class MyLayout_N_M :public MyLayout_N
{
public:
	virtual~MyLayout_N_M();
	static MyLayout_N_M*create(std::string name, std::string motto, float width, float height);
	bool init(std::string name, std::string motto, float width, float height);
	void setMottoPosition(Vec2 vec);

	void setMottoDimensions(float width, float height);
	Rect getmottoBoundingBox();

protected:
	CC_SYNTHESIZE(std::string, motto, _Motto);
	CC_SYNTHESIZE_READONLY(Label*, labelMotto, _LabelMotto);
};

