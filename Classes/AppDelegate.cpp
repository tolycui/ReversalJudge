#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "ScreenBlink.h"
#include "SceneManage.h"
#include "SceneMain.h"

USING_NS_CC;


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
	SceneManage::destroyInstance();
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		glview = GLViewImpl::createWithRect("ReversalJudge", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
        director->setOpenGLView(glview);
    }

	director->getOpenGLView()->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, 
		ResolutionPolicy::FIXED_HEIGHT);

    // turn on display FPS
    director->setDisplayStats(true);

	Size frameSize = glview->getFrameSize();

	std::vector<std::string> searchPaths =FileUtils::getInstance()->getSearchPaths();
	std::string searchPathBasic = searchPaths[0];

	FileUtils::getInstance()->purgeCachedEntries();
	if (frameSize.height>mediumResolutionSize.height)
	{
		director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height,
			largeResolutionSize.width / designResolutionSize.width));

		searchPaths.insert(searchPaths.begin(), searchPathBasic + "large");
	}
	else if (frameSize.height > smallResolutionSize.height)
	{
		director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height,
			mediumResolutionSize.width / designResolutionSize.width));
		searchPaths.insert(searchPaths.begin(), searchPathBasic + "medium");
	}
	else
	{
		director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height,
			smallResolutionSize.width/designResolutionSize.width));
		searchPaths.insert(searchPaths.begin(), searchPathBasic+"small");
	}

	std::vector<std::string> strvec = FileUtils::getInstance()->getSearchPaths();
	FileUtils::getInstance()->setSearchPaths(searchPaths);
	strvec = FileUtils::getInstance()->getSearchPaths();
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

	Scene *sc = SceneMain::createScene();
	director->replaceScene(sc);
	//SceneManage::getInstance()->initBlinkScene();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
