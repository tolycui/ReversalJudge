#pragma once
#include "MyLayout_N_M.h"
#include "PersonHead.h"
#include "ui/CocosGUI.h"
using namespace ui;

class MyLayout_N_M_P_noT :public MyLayout_N_M
{
public:
	MyLayout_N_M_P_noT();
	virtual~MyLayout_N_M_P_noT();
	static MyLayout_N_M_P_noT*create(std::string name, std::string motto, std::string headFile, int diameter,float width, float height);
	bool init(std::string name, std::string motto, std::string headFile, int diameter, float width, float height);

	void setHeadPosition_my(Vec2 vec);
	Rect getHeadBoundingBox();
protected:
	CC_SYNTHESIZE_READONLY(PersonHead*, personHead, _personHead);
};

