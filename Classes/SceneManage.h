#pragma once
#include "SystemHead.h"
#include "GameProgress.h"
#include "PublicDefine.h"




class SceneManage:public cocos2d::Ref
{
public:
	/*
	传入进程类型和进程索引,获取当前要执行的场景和人物对话等;
	储存事件发生在:
	差一个储存类;
	*/
	CREATE_INSTANCE_FUNC(SceneManage);
	DESTROY_INSTANCE_FUNC();
	//static cocos2d::Scene* createScene(GameProgress* gameProg);
	//static GameSceneManage*create(GameProgress* gameProg);
	void initBlinkScene();
protected:
	SceneManage(){}
	GameProgress*gameProg;
	virtual bool init();
	virtual void registerChangeSceneEvent();
	void receiveChangeScene(EventCustom* event);
	void changeScene(GameProgress* UserData);


};

