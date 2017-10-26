#pragma once
#include "SystemHead.h"
#include "MyLayout_N_M_P_noT.h"
class MyLayout_N_M_P_OTHER :
	public MyLayout_N_M_P_noT
{
public:
	virtual~MyLayout_N_M_P_OTHER();
	static MyLayout_N_M_P_OTHER*create(std::string name, std::string motto, std::string headFile,
		int diameter = PERSONHEADHEIGHT_OTHER, float width = FRAMESIZE.width * 22 / 24, float height = LISTITEM_HEIGHT);
	bool init(std::string name, std::string motto, std::string headFile, int diameter, float width, float height);
protected:
	//用事件订阅分发机制通知聊完天的时候是发消息调用本类的回调函数,可以绑在init函数中;
	void changeName_Other(Ref* pData);
	//触摸事件;
	//bool onTouchBegan(Touch *touch, Event *unusedEvent) override;
	//void onTouchMoved(Touch *touch, Event *unusedEvent) override;
	//void onTouchEnded(Touch *touch, Event *unusedEvent) override;
	//void onTouchCancelled(Touch *touch, Event *unusedEvent) override;
	void MyClicked(Ref *pSender, Widget::TouchEventType type);
	//进入聊天
	void EnterDialog(MyLayout_N_M_P_OTHER * pSender);
	//弹出修改姓名框
	void sendChangeNameother(float dt);
	//按钮
	CC_SYNTHESIZE_READONLY(Button*, button, _Button);
	bool isMove = false;
	bool isDo = false;
};

