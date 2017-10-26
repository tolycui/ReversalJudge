#pragma once
#include "SystemHead.h"
#include "ui/CocosGUI.h"
#include "MyLayout_N_M_P_OTHER.h"
using namespace ui;

class LayerChangeName :public Layer, public EditBoxDelegate
{
public:
	LayerChangeName();
	virtual~LayerChangeName();
	static LayerChangeName*create(MyLayout_N_M_P_OTHER * data);
	bool init(MyLayout_N_M_P_OTHER * data);
	void changeNameOutput(Ref* pSender, Widget::TouchEventType type);
	void editBoxReturn(EditBox* editBox);    // 当按下返回按钮或触摸屏幕外部区域时调用, 此时应该取消这次修改;
	void editBoxEditingDidBegin(EditBox* editBox); //当获取输入框时触发的函数;
	void editBoxTextChanged(EditBox* editBox, const std::string& text); //当box里面的文字改变时

protected:
	MyLayout_N_M_P_OTHER * data;
	ui::Layout * lyChangeName;
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	Button* btn;
	bool isMoved=false;
	bool isCancelMoved = false;
};

