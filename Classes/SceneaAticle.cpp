#include "SceneaAticle.h"


Scene* SceneaAticle::createScene()
{
	auto scene = Scene::create();
	auto layer = SceneaAticle::create();
	scene->addChild(layer);
	return scene;
}