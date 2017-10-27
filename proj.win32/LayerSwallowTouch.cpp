#include "LayerSwallowTouch.h"


LayerSwallowTouch::~LayerSwallowTouch()
{
	removeAllChildren();
}

void LayerSwallowTouch::DelegateEdixBox()
{
	editBox->setDelegate(this);
}

void LayerSwallowTouch::editBoxReturn(EditBox* editBox)
{

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
		MessageBox("名字长度不能大于7个中文", "提示");
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

void LayerSwallowTouch::onTouchMoved2(Touch *touch, Event *unused_event)
{

}

void LayerSwallowTouch::onTouchEnded2(Touch *touch, Event *unused_event)
{

}

void LayerSwallowTouch::btnConfirmCallback(Ref* pSender, Widget::TouchEventType type)
{

}

void LayerSwallowTouch::btnCancelCallback(Ref* pSender, Widget::TouchEventType type)
{

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

	return true;
}
