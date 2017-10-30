#include "LayerSwallowTouch.h"


LayerSwallowTouch::~LayerSwallowTouch()
{
	//removeAllChildren();
	////CC_SAFE_RELEASE(label);
	//_eventDispatcher->removeEventListener(this->touch);
	sendMessage();

}

void LayerSwallowTouch::DelegateEdixBox()
{
	editBox->setDelegate(this);
}


void LayerSwallowTouch::editBoxEditingDidBegin(EditBox* editBox)
{
	if (!textTemp.empty())
	{
		editBox->setText(textTemp.c_str());
	}
	else
	{
		editBox->setText(label->getString().c_str());
	}
}

void LayerSwallowTouch::editBoxTextChanged(EditBox* editBox, const std::string& text)
{
	if (text.size() > 30)
	{
		MessageBox("name length not longer 15 chars", "warning");
		if (!textTemp.empty())
		{
			editBox->setText(textTemp.c_str());
		}
		else
		{
			editBox->setText(label->getString().c_str());
		}
	}
	else
	{
		textTemp = text;
		log("记录textTemp");
	}
}

bool LayerSwallowTouch::onTouchBegan2(Touch *touch, Event *unused_event)
{
	return true;
}

LayerSwallowTouch* LayerSwallowTouch::create(Label* label)
{
	LayerSwallowTouch *ly = new LayerSwallowTouch();
	if (ly&&ly->init(label))
	{
		ly->autorelease();
		return ly;
	}
	CC_SAFE_DELETE(ly);
	return ly;
}

bool LayerSwallowTouch::init(Label* label)
{
	if (!LayerColor::initWithColor(Color4B::GRAY))
	{
		return false;
	}

	this->setOpacity(100);
	this->label = label;
	label->retain();

	editBox = EditBox::create(Size(200, 40), "EditBg.jpg");
	editBox->setFont("Arial", 32);
	editBox->setFontColor(Color4B::BLACK);
	editBox->setReturnType(EditBox::KeyboardReturnType::DONE);
	editBox->setPlaceHolder(label->getString().c_str());
	editBox->setPlaceholderFont("Arial", 32);
	editBox->setPosition(Vec2(FRAMESIZE.width / 2, FRAMESIZE.height / 2));

	btnConfirm = Button::create("botton.png","botton_HL.png");
	btnConfirm->setScaleX(80 / btnConfirm->getContentSize().width);
	btnConfirm->setScaleY(20 / btnConfirm->getContentSize().height);

	btnCancel = Button::create("botton.png", "botton_HL.png");
	btnCancel->setScaleX(80 / btnCancel->getContentSize().width);
	btnCancel->setScaleY(20 / btnCancel->getContentSize().height);

	btnConfirm->setAnchorPoint(Vec2(0, 1));
	btnCancel->setAnchorPoint(Vec2(0, 1));
	btnConfirm->setPosition(Vec2(0, - 10 ));
	btnCancel->setPosition(Vec2(100, -10));

	btnConfirm->setTitleFontName("Arial");
	btnCancel->setTitleFontName("Arial");
	btnConfirm->setTitleFontSize(52);
	btnCancel->setTitleFontSize(52);
	btnConfirm->setTitleText("confirm");
	btnCancel->setTitleText("cancel");

	bool test =btnConfirm->isSwallowTouches();

	this->setSwallowsTouches(true);
	btnConfirm->setSwallowTouches(true);
	btnCancel->setSwallowTouches(true);
	editBox->setSwallowTouches(true);

	editBox->addChild(btnConfirm);
	editBox->addChild(btnCancel);

	btnConfirm->addTouchEventListener(CC_CALLBACK_2(LayerSwallowTouch::btnConfirmCallback, this));
	btnCancel->addTouchEventListener(CC_CALLBACK_2(LayerSwallowTouch::btnCancelCallback, this));
	this->addChild(editBox);
	DelegateEdixBox();


	touch = EventListenerTouchOneByOne::create();
	touch->setSwallowTouches(true);
	touch->onTouchBegan = CC_CALLBACK_2(LayerSwallowTouch::onTouchBegan2, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch,this);
	return true;
}

void LayerSwallowTouch::btnConfirmCallback(Ref* pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
	{
													   break;
	}
	case cocos2d::ui::Widget::TouchEventType::MOVED:
	{
													   btnConfirmMoved = true;
													   break;
	}	
	case cocos2d::ui::Widget::TouchEventType::ENDED:
	{
													   if (!btnConfirmMoved)
													   {
														   label->setString(this->editBox->getText());
													       log("Confirm change");  
														   removeFromParent();
														   break;
													   }
													   else
													   {
														   btnConfirmMoved = false;
														   break;
													   }
	}
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
	{
														  break;
	}
	}
	
}

void LayerSwallowTouch::btnCancelCallback(Ref* pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
	{
													   btnCancenMoved = true;
													   break;
	}	
	case cocos2d::ui::Widget::TouchEventType::ENDED:
	{
													   if (!btnCancenMoved)
													   {
														   log("cancel");
														   removeFromParent();
													   }
													   btnCancenMoved = false;
													   break;
	}
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}

}

void LayerSwallowTouch::sendMessage()
{
	//EventCustom ev = EventCustom("changeNameRemove");
	
	EventCustom ev = EventCustom("TouchRecover");
	_eventDispatcher->dispatchEvent(&ev);

}
