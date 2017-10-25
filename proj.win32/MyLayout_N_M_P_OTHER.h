#pragma once
#include "SystemHead.h"
#include "MyLayout_N_M_P_noT.h"
class MyLayout_N_M_P_OTHER :
	public MyLayout_N_M_P_noT
{
public:
	virtual~MyLayout_N_M_P_OTHER();
	static MyLayout_N_M_P_OTHER*create(std::string name, std::string motto, std::string headFile,
		int diameter = PERSONHEADHEIGHT_OTHER, float width = 100, float height=200);
	bool init(std::string name, std::string motto, std::string headFile, int diameter, float width, float height);
protected:
	//用事件订阅分发机制通知聊完天的时候是发消息调用本类的回调函数,可以绑在init函数中;
	void changeName_Other(Ref* pData);
	//触摸事件;
	bool onTouchBegan(Touch *touch, Event *unusedEvent) override;
	void onTouchMoved(Touch *touch, Event *unusedEvent) override;
	void onTouchEnded(Touch *touch, Event *unusedEvent) override;
	void onTouchCancelled(Touch *touch, Event *unusedEvent) override;

	//进入聊天
	void EnterDialog();
	//弹出修改姓名框
	void showLayoutChangeName();
};

