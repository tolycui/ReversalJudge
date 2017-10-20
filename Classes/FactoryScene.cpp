#include "FactoryScene.h"
#include "SceneaAticle.h"
#include "SceneCourt.h"
#include "SceneMain.h"
#include "SceneDialogue.h"
#include "SceneRoom.h"
#include "SceneStory.h"
#include "TitleScene.h"
#include "ScreenBlink.h"

Scene* FactoryScene::createScene(int SceneType)
{
	Scene *pScene = nullptr;
	switch (SceneType)
	{
	case EnumSceneType::ScreenBlink:
	{
									   pScene = ScreenBlink::createScene();
									   break;
	}
	case EnumSceneType::TitleScene:
	{
									  pScene = TitleScene::createScene();
									  break;
	}
	case EnumSceneType::SceneStory:
	{
									  pScene = SceneStory::createScene();
									  break;
	}
	case EnumSceneType::SceneMain:
	{
									 pScene = SceneMain::createScene();
									 break;
	}
	case EnumSceneType::SceneDialogue:
	{
										 pScene = SceneDialogue::createScene();
										 break;
	}
	case EnumSceneType::SceneaAticle:
	{
										pScene = SceneaAticle::createScene();
										break;
	case EnumSceneType::SceneRoom:
	{
									 pScene = SceneRoom::createScene();
									 break;
	}
	case EnumSceneType::SceneCourt:
	{
									  pScene = SceneCourt::createScene();
									  break;
	}
	}
	default:
		break;
	}
	return pScene;
}
