#include "GameProgress.h"


GameProgress::GameProgress()
{

}


GameProgress::~GameProgress()
{
}

GameProgress * GameProgress::create(int Index, progTypeEnum SceneType,progTypeEnum ProgressType, int TypeNum)
{
	GameProgress * gameProgress = new GameProgress();
	if (gameProgress->init(Index, SceneType, ProgressType, TypeNum))
	{
		gameProgress->autorelease();
		return gameProgress;
	}
	CC_SAFE_DELETE(gameProgress);
	return gameProgress;
}

bool GameProgress::init(int Index, progTypeEnum SceneType, progTypeEnum ProgressType, int TypeNum)
{
	if (!Node::init())
	{
		return false;
	}
	this->Index = Index;
	this->ProgressType = ProgressType;
	this->TypeNum = TypeNum;
	this->SceneType = SceneType;
	return true;
}
