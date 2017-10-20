//
//  FileLoadUtil.h
//  Chapter9_6_LoadCsv
//
//  Created by 闫鑫 on 14-6-14.
//
//

#ifndef __Chapter9_6_LoadCsv__FileLoadUtil__
#define __Chapter9_6_LoadCsv__FileLoadUtil__

#include "cocos2d.h"
#include "StringUtil.h"
USING_NS_CC;

class FileLoadUtil
{
public:
	/*
	将文件的内容以行的形式读取到StrVec中;
	*/
    StrVec getDataLines(const std::string &rSCsvFilePath)
    {
        StrVec linesList;
        
		if (!cocos2d::FileUtils::getInstance()->isFileExist(rSCsvFilePath))
		{
			log("file is not exist");
			return linesList;
		}
            
        
        ssize_t pSize = 0;
        
        StringUtil tStringUtil;
        //获取文件信息,存入unsigned char*
        unsigned char *chDatas = cocos2d::FileUtils::getInstance()->getFileData(rSCsvFilePath, "r", &pSize);
        
        if(chDatas) 
			linesList = tStringUtil.split((char *)chDatas, "\n");
        
        return linesList;
    }
};

#endif /* defined(__Chapter9_6_LoadCsv__FileLoadUtil__) */
