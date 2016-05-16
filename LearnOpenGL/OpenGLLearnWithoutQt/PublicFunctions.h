/*********************************************************************************
  * Copyright(C) 2009   ChengDu Everimaging
  *
  *FileName:          PublicFunctions.h
  *
  *Author:         	   dai xiaobing
  *
  *Date:         	       2016-5-13
  *
  *Description:			
**********************************************************************************/
#ifndef PublicFunctions_h__
#define PublicFunctions_h__
#include "stdafx.h"

namespace PublicFunctions
{
	//加载BMP文件纹理
	bool loadGLTexturesWithBMP2D(GLuint& textureID, const std::string& filePath);
}

#endif // PublicFunctions_h__
