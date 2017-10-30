#pragma once
#include "cocos2d.h"
USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(562, 1000);

static cocos2d::Size smallResolutionSize = cocos2d::Size(640, 1136);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(750, 1334);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1080, 1920);

//游戏进程csv
#define PATH_CSV_OF_GAMEPROGRESS ("csv/GameProgress.csv")

#define  FRAMESIZE   (((Director::getInstance())->getOpenGLView())->getFrameSize())
#define  winSize  (Director::getInstance()->getWinSize())

//字体
#define FNT1 "fnt/JDJHCU.TTF"
#define CHINESE_FNT "fnt/Myfnt.fnt"
#define CHINESE_XML "chinesexml/BottomBarItem.xml"
#define CHINESE_XML2 "chinesexml/chinese.xml"

//主界面底部按钮的大小
#define WID  (FRAMESIZE.width / 12)
//主界面底部文字高度
#define BOTTOMBARTEXT (FRAMESIZE.height / 48)  //bar text height
//主界面底部条的高度
#define  BARHIGHT (FRAMESIZE.height/12)
//主界面主人公模块底部到屏幕顶部距离
#define PERSON_MODULE_BOTTOM (FRAMESIZE.height / 4)
//聊天列表的宽度和高度;
#define LISTWID FRAMESIZE.width * 23 / 24
#define LISTHEIGHT (FRAMESIZE.height - PERSON_MODULE_BOTTOM - BARHIGHT)
//聊天列表一个Item的高度
#define LISTITEM_HEIGHT (FRAMESIZE.height / 10)



//人物聊天头像大小
#define PERSONHEADHEIGHT_OWN (FRAMESIZE.width/5)
#define PERSONHEADHEIGHT_OTHER (FRAMESIZE.width/10)

//人物聊天头像文件路径
#define PERSONHEAD_PICPATH "PersonagePic/"

//人物名字
extern std::string PersonName_other[];
extern std::string PersonName_own[];

//页面背景图
#define LAYER_PAGEA_BGPIC "SceneBgPic/Scengbg1.jpg"
#define LAYER_PAGEB_BGPIC "SceneBgPic/Scengbg2.jpg"
#define LAYER_PAGEC_BGPIC "SceneBgPic/Scengbg3.jpg"
#define LAYER_PAGED_BGPIC "SceneBgPic/Scengbg4.jpg"

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