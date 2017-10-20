#include "SceneStory.h"


SceneStory::SceneStory()
{
}


SceneStory::~SceneStory()
{
}


Scene* SceneStory::createScene()
{
	auto scene = Scene::create();
	auto layer = SceneStory::create();
	scene->addChild(layer);
	return scene;
}