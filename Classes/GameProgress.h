#pragma once
#include "SystemHead.h"

enum progTypeEnum   //运行进程类型;
{
	Lines = 1,    //对话
	LinesSelect,  //对话选择
	PropsSelect,  //道具选择
	ExhibitSelect, //证物选择
	WitnessSelect  //证人选择
};

enum EnumProgressCsv  //csv数据结构
{
	Index = 0,
	SceneType,
	ProgressType,
	LinesNum,
	LinesSelectNum,
	PropsSelectNum,
	ExhibitSelectNum,
	WitnessSelectNum
};


class GameProgress:public cocos2d::Node
{
public:
	static GameProgress * create(int Index, progTypeEnum SceneType, progTypeEnum ProgressType, int TypeNum);
	bool init(int Index, progTypeEnum SceneType, progTypeEnum ProgressType, int TypeNum);
	GameProgress();
	~GameProgress();
private:
	CC_SYNTHESIZE(int, Index, _Index);
	CC_SYNTHESIZE(progTypeEnum, ProgressType, _ProgressType);
	CC_SYNTHESIZE(int, TypeNum, _TypeNum);
	CC_SYNTHESIZE(int, SceneType, _SceneType);
	//int LinesSelectNum;
	//int PropsSelectNum;
	//int ExhibitSelectNum;
	//int WitnessSelectNum;
};



