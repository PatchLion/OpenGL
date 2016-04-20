/*********************************************************************************
  * 
  *
  *FileName:          PrimrestartTest.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		重启图元测试
**********************************************************************************/
#ifndef PrimrestartTest_h__
#define PrimrestartTest_h__

#include "LearnOpenGLBase.h"

class CPrimrestartTest : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CPrimrestartTest();
	~CPrimrestartTest(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // PrimrestartTest_h__
