#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace ui;

class LayerSwallowTouch :public LayerColor, public EditBoxDelegate
{
public:
	virtual ~LayerSwallowTouch();
	static LayerSwallowTouch* create(Label* label);
	bool init(Label* label);
	CC_SYNTHESIZE_READONLY(Button *, btnConfirm, _BtnConfirm);
	CC_SYNTHESIZE_READONLY(Button *, btnCancel, _BtnCancel);
	CC_SYNTHESIZE_READONLY(EditBox*, editBox, _EditBox);
	CC_SYNTHESIZE_READONLY(Label*, label, _Label);          //传入的要改变的文本;
	bool btnConfirmMoved=false;
	bool btnCancenMoved = false;
	bool btnLayerMoved = false;

	void DelegateEdixBox();
	virtual void editBoxReturn(EditBox* editBox){};    // 当按下返回按钮或触摸屏幕外部区域时调用, 此时应该取消这次修改;
	virtual void editBoxEditingDidBegin(EditBox* editBox);//当获取输入框时触发的函数;
	virtual void editBoxTextChanged(EditBox* editBox, const std::string& text); //当box里面的文字改变时
	std::string textTemp;   //缓存用户的输入
	//文本输入框层的触摸函数
	virtual bool onTouchBegan2(Touch *touch, Event *unused_event);
	virtual void onTouchMoved2(Touch *touch, Event *unused_event);
	virtual void onTouchEnded2(Touch *touch, Event *unused_event);

	virtual void btnConfirmCallback(Ref* pSender, Widget::TouchEventType type);
	virtual void btnCancelCallback(Ref* pSender, Widget::TouchEventType type);
};

