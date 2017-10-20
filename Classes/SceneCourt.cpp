#include "SceneCourt.h"


Scene* SceneCourt::createScene()
{
	auto scene = Scene::create();
	auto layer = SceneCourt::create();
	scene->addChild(layer);
	return scene;
}