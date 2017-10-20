#include "SceneRoom.h"


SceneRoom::SceneRoom()
{
}


SceneRoom::~SceneRoom()
{
}


Scene* SceneRoom::createScene()
{
	auto scene = Scene::create();
	auto layer = SceneRoom::create();
	scene->addChild(layer);
	return scene;
}