#pragma once
#include "SystemHead.h"
class LayerBg :
	public Layer
{
public:
	LayerBg();
	virtual~LayerBg();
	static LayerBg*create(std::string filePath);
	bool init(std::string filePath);
};

