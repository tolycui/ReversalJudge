#include "PageADialogMudule.h"


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
	//setBackGroundImage("BottomItem3.jpg");//设置北京图片
	//setBackGroundImageScale9Enabled(true);//设置图片为九宫格格式。
	setContentSize(Size(LISTWID, LISTHEIGHT));
	setAnchorPoint(Point(0,1));
	float f = this->getContentSize().width;
	setPosition(Point(FRAMESIZE.width - this->getContentSize().width, FRAMESIZE.height - PERSON_MODULE_BOTTOM));
	//setScrollBarEnabled(false);//设置滚动条不显示;
	setScrollBarPositionFromCorner(Vec2(2, 0));  //设置滚动条距离ViewList最右上角(竖排列) 或最左下角(横排列)的距离;
	setScrollBarWidth(FRAMESIZE.width / 100);  //设置滚动条宽度
	Size size = Size(FRAMESIZE.width * 22 / 24, 100);
	for (int i = 0; i < 20; ++i)
	{
		std::string ccstr = StringUtils::format("listview_item_%d", i);
		_array.push_back(ccstr);
	}

	for (int i = 0; i < 15; ++i)
	{
		/*auto image = ImageView::create("MainSceneBg.jpg");
		image->setScale(size.height / image->getContentSize().height);
		
		image->setPosition(Point(image->getContentSize().width / 2, size.height / 2));*/

		auto bt = Button::create("botton.jpg", "botton_HL.jpg");

		bt->setScale9Enabled(true);
		bt->setScaleY(size.height / bt->getContentSize().height);
		bt->setScaleX(size.width / bt->getContentSize().width);
		//bt->setContentSize(Size(size.width / 2, size.height / 2));

		bt->setPosition(Point(size.width/2, size.height / 2));

		bt->setTitleText(_array.at(i));
		bt->setTitleFontSize(32);
		//itme的布局  
		auto layout = Layout::create();

		//layout->setBackGroundImageScale9Enabled(true);
		//layout->setBackGroundColor(Color3B::WHITE);

	//	layout->setBackGroundImage("nd3_white_bg.9.png");

		layout->setContentSize(size);
	//	layout->addChild(image);
		layout->addChild(bt);
		addChild(layout);
	}

	setItemsMargin(FRAMESIZE.height/80);
	return true;
}
