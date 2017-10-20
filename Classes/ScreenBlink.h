#ifndef __ScreenBlink_SCENE_H__
#define __ScreenBlink_SCENE_H__

#include "tinyxml2/tinyxml2.h"
#include "SystemHead.h"
#include "csvLoadUtils/CsvUtil.h"

USING_NS_CC;

class ScreenBlink : public cocos2d::Layer
{
private:
	int m_nNumberOfLoaded;
	std::thread * _loadingAudioThread;
	~ScreenBlink();
	//void PreLoadAudio();
	//void loadingTextureCallBack(cocos2d::Texture2D * texture);
	//void delayCall(float dt);
	//void onExit();

public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(ScreenBlink);
	cocos2d::Node* test;
	
	//资源预加载
	//void preLoadPic();
	void preLoadSource(const std::string & csvFilePatch); //预加载csv文件;
	void GoToTitleScene();
};

#endif // __ScreenBlink_SCENE_H__
