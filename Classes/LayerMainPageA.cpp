#include "LayerMainPageA.h"
#include "LayerChangeName.h"
#include "MyLayout_N_M_P_OTHER.h"

LayerMainPageA::~LayerMainPageA()
{
	removeAllChildren();
	this->_eventDispatcher->removeCustomEventListeners("changeNameOther");
	this->_eventDispatcher->removeCustomEventListeners("TouchRecover");
}

bool LayerMainPageA::init()
{
	if (!Layer::init())
	{
		return false;
	}
	this->setZOrder(1);
	moduleOwn = PageAPersonModule::create();
	addChild(moduleOwn);
	moduleOwn->setName("Own");
	dialog = PageADialogMudule::create();
	addChild(dialog);
	dialog->setName("Dialog");

	this->_eventDispatcher->addCustomEventListener("changeNameOther", CC_CALLBACK_1(LayerMainPageA::showLayoutChangeNameOther, this));
	
	this->_eventDispatcher->addCustomEventListener("TouchRecover", CC_CALLBACK_1(LayerMainPageA::RecoverListTouch, this));
	return true;
}

void LayerMainPageA::showLayoutChangeNameOther(EventCustom* event)
{
	log("LayerMainPageA::showLayoutChangeNameOther");
	MyLayout_N_M_P_OTHER * data = reinterpret_cast<MyLayout_N_M_P_OTHER*>(event->getUserData());
	int tag = data->getTag();

	this->dialog->setTouchEnabled(false);
	//auto btVec =this->dialog->getChildren();
	//for (auto bt:btVec)
	//{
	//	MyLayout_N_M_P_OTHER* ly = (MyLayout_N_M_P_OTHER*)bt;
	//	
	//	btn->setTouchEnabled(false);
	//}
	LayerChangeName* layerChangeName = LayerChangeName::create(data);
	layerChangeName->setName("layerChangeName");
	addChild(layerChangeName);

	layerChangeName->setZOrder(100);

}

void LayerMainPageA::RecoverListTouch(EventCustom* event)
{
	removeChildByName("layerChangeName");
	this->dialog->setTouchEnabled(true);
}

