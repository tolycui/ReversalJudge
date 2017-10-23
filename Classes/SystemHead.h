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

#define BOTTOMBARTEXT (FRAMESIZE.height / 48)  //bar text height
#define WID  (FRAMESIZE.width / 12)

#define CHINESE_FNT "fnt/Myfnt.fnt"
#define CHINESE_XML "chinesexml/BottomBarItem.xml"

enum EnumMyZorder
{
	BG=-1,
	SPRITE=1,
	MENU=2
};

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


#if(CC_TARGET_PLATFORM ==CC_PLATFORM_IOS)

#define PIC ".jpg"
#define bg_music_2 "sount/game_bg.aifc"
#define sound_1   "sound/Blip.caf"
#define sound_2   "sound/Explosion.caf"

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)

#define PIC ".jpg"
#define bg_music_2  "sound/game_bg.wav"
#define sound_1   "sound/Blip.wav"
#define sound_2   "sound/Explosion.wav"

#else
#define PIC ".jpg"

#endif