#include "MyUtils.h"
MyUtils * MyUtils::ptr_only = nullptr;
USING_NS_CC;

MyUtils::~MyUtils()
{
	CC_SAFE_DELETE(ptr_only);
}

MyUtils* MyUtils::getInstence()
{
	if (ptr_only!=nullptr)
	{
		return ptr_only;
	}
	ptr_only = new MyUtils();
	return ptr_only;
}

void MyUtils::dumpXmlNode(tinyxml2::XMLElement *node, std::string prefix)
{
	log((prefix + "%s").c_str(), node->Name());
	auto nodeAttr = node->FirstAttribute();
	//打印节点的属性
	prefix += "/t";
	while (nodeAttr)
	{
		log((prefix + "%s attribute %s - %d").c_str(), node->Name(), nodeAttr->Name(), nodeAttr->IntValue());
		nodeAttr = nodeAttr->Next();
	}
	//递归显示子节点的属性
	//auto child = node->FirstChildElement();
	//while (child)
	//{
	//	dumpXmlNode(child, prefix);
	//	child = child->NextSiblingElement();
	//}


}

/*
将xml文件的内容读取到xmlDocument中;
*/
tinyxml2::XMLDocument * MyUtils::ParseXML(char* xmlFilePath,tinyxml2::XMLDocument * xmlDoc)
{
	std::string xmlFile = "xml/myxml.xml";  // »ñÈ¡xmlÎÄ¼þÃû;
	std::string xmlBuffer = FileUtils::getInstance()->getStringFromFile(xmlFile);//¶ÁÈ¡xmlÎÄ¼þÄÚÈÝµ½stringbufferÖÐ;
	if (xmlBuffer.empty())
	{
		log("load xml file %s faile", xmlFile.c_str());
		return nullptr;
	}
	//解析xmlDoc;
	xmlDoc->Parse(xmlBuffer.c_str(), xmlBuffer.size());
	
	return xmlDoc;
}

/*
创建节点结构
*/
tinyxml2::XMLElement * MyUtils::buildXmlNode(tinyxml2::XMLDocument *doc)
{
	//玩家节点
	tinyxml2::XMLElement * playerNode = doc->NewElement("player");
	playerNode->SetAttribute("attack", 99);
	playerNode->SetAttribute("hp", 100);
	playerNode->SetAttribute("fet", 50);
	
	//武器节点
	tinyxml2::XMLElement * weapon = doc->NewElement("weapon");
	weapon->SetAttribute("attack", 50);
	playerNode->LinkEndChild(weapon);

	return playerNode;
}

void MyUtils::SaveXml()
{

}


GameProgress* MyUtils::createProgressNow(int index)
{
	StrVec _progressRow = CsvUtil::getInstance()->getRowData(index, PATH_CSV_OF_GAMEPROGRESS);
	progTypeEnum _SceneType = (progTypeEnum)atoi(_progressRow.at(SceneType).c_str());
	progTypeEnum _progressType = (progTypeEnum)atoi(_progressRow.at(ProgressType).c_str());
	int typeNum = atoi(_progressRow.at(ProgressType + _progressType).c_str());

	auto PGameProgress = GameProgress::create(index, _SceneType,_progressType, typeNum);
	PGameProgress->retain();
	PGameProgress->autorelease();
	return PGameProgress;
}
