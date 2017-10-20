#include "MyMenuItemImage.h"


MyMenuItemImage::MyMenuItemImage()
{
}


MyMenuItemImage::~MyMenuItemImage()
{
}

bool MyMenuItemImage::init()
{
	if (!MenuItemImage::init())
		return false;

	return true;
}
