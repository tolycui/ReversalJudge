//默认utf-8保存
#include "SceneDialogue.h"
#pragma execution_character_set("utf-8")

SceneDialogue::~SceneDialogue()
{
	removeAllChildrenWithCleanup(true);
}

Scene* SceneDialogue::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SceneDialogue::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance

bool SceneDialogue::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

//void SceneGameDialogue::proLoadPic()
//{
//
//}



