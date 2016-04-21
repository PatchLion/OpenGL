/*********************************************************************************
  * 
  *
  *FileName:          BuffersTest.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		绘制正二十面体
**********************************************************************************/
#ifndef BuffersTest_h__
#define BuffersTest_h__

#include "LearnOpenGLBase.h"

class CBuffersTest : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CBuffersTest();
	~CBuffersTest(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // BuffersTest_h__
