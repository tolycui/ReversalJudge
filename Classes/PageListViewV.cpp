#include "PageListViewV.h"


PageListViewV::PageListViewV()
{
}


PageListViewV::~PageListViewV()
{
}

bool PageListViewV::init()
{
	return true;
}

Layout* PageListViewV::getLayoutByName()
{
	return this->LayerVec.at(0);
}

void PageListViewV::setLayoutName(std::string name)
{

}
