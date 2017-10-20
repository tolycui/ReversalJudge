#pragma once
#include "cocos2d.h"
USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(562, 1000);

static cocos2d::Size smallResolutionSize = cocos2d::Size(640, 1136);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(750, 1334);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1080, 1920);

#define PATH_CSV_OF_GAMEPROGRESS ("csv/GameProgress.csv")
#define  FRAMESIZE   (((Director::getInstance())->getOpenGLView())->getFrameSize())
#define  winSize  (Director::getInstance()->getWinSize())

enum EnumSceneType
{
	ScreenBlink = 1,
	TitleScene,
	SceneStory,
	SceneMain,
	SceneDialogue,
	SceneaAticle,
	SceneRoom,
	SceneCourt
};