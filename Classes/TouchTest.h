#pragma once
#include "cocos2d.h"
USING_NS_CC;


class TouchTest :public Layer
{
public:
	enum MyEnum
	{
		BY474
	};
	static Scene *createScene();
	bool init();
	CREATE_FUNC(TouchTest);
	virtual bool onTouchBegan(Touch *touch, Event *unused_event)override;
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);
	void gameOver(EventCustom* event);
	SpriteBatchNode * batchNode;
	
};