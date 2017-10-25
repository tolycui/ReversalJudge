#include "PageADialogMudule.h"
#include "MyLayout_N_M_P_OTHER.h"

PageADialogMudule::PageADialogMudule()
{
}


PageADialogMudule::~PageADialogMudule()
{
	_array.clear();
}

bool PageADialogMudule::init()
{
	if (!ListView::init())
	{
		return false;
	}

	setDirection(ui::ScrollView::Direction::VERTICAL);//设置方向为垂直方向
	setBounceEnabled(true);
	setContentSize(Size(LISTWID, LISTHEIGHT));
	setAnchorPoint(Point(0,1));
	float f = this->getContentSize().width;
	setPosition(Point(FRAMESIZE.width - this->getContentSize().width, FRAMESIZE.height - PERSON_MODULE_BOTTOM));
	//setScrollBarEnabled(false);//设置滚动条不显示;
	setScrollBarPositionFromCorner(Vec2(2, 0));  //设置滚动条距离ViewList最右上角(竖排列) 或最左下角(横排列)的距离;
	setScrollBarWidth(FRAMESIZE.width / 100);  //设置滚动条宽度
	for (int i = 0; i < 20; ++i)
	{
		std::string ccstr = StringUtils::format("listview_item_%d", i);
		_array.push_back(ccstr);
	}

	for (int i = 0; i < 15; ++i)
	{
	//	/*auto image = ImageView::create("MainSceneBg.jpg");
	//	image->setScale(size.height / image->getContentSize().height);
	//	
	//	image->setPosition(Point(image->getContentSize().width / 2, size.height / 2));*/

	//	auto bt = Button::create("botton.jpg", "botton_HL.jpg");

	//	bt->setScale9Enabled(true);
	//	bt->setScaleY(size.height / bt->getContentSize().height);
	//	bt->setScaleX(size.width / bt->getContentSize().width);
	//	//bt->setContentSize(Size(size.width / 2, size.height / 2));

	//	bt->setPosition(Point(size.width/2, size.height / 2));

	//	bt->setTitleText(_array.at(i));
	//	bt->setTitleFontSize(32);
	//	//itme的布局  
	//	auto layout = Layout::create();

	//	//layout->setBackGroundImageScale9Enabled(true);
	//	//layout->setBackGroundColor(Color3B::WHITE);

	////	layout->setBackGroundImage("nd3_white_bg.9.png");

	//	layout->setContentSize(size);
	////	layout->addChild(image);
	//	layout->addChild(bt);
		auto layout = MyLayout_N_M_P_OTHER::create("didi", "nizaima?", "BottomItem4.jpg");
		layout->setHeadPosition_my(Vec2(layout->getContentSize().width / 4, layout->getContentSize().height / 2));
		layout->setNamePosition_my(Vec2(layout->getContentSize().width / 3, layout->getContentSize().height * 2 / 3));
		layout->setMottoPosition_my(Vec2(layout->getContentSize().width / 3, layout->getContentSize().height / 3));
		addChild(layout);
	}

	setItemsMargin(FRAMESIZE.height/80);  //间隔;
	return true;
}
