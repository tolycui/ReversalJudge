#ifndef __SceneGameDialogue_SCENE_H__
#define __SceneGameDialogue_SCENE_H__
//默认utf-8保存
#pragma execution_character_set("utf-8")
#include "tinyxml2/tinyxml2.h"
#include "SystemHead.h"

class SceneDialogue : public cocos2d::Layer
{
private:
	~SceneDialogue();
	//void PreLoadAudio();
	//void loadingTextureCallBack(cocos2d::Texture2D * texture);
	//void delayCall(float dt);
	//void onExit();

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SceneDialogue);
	//资源预加载
	//void proLoadPic();
};

#endif // __SceneGameDialogue_SCENE_H__
