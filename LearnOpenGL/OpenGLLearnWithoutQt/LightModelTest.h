/*********************************************************************************
  * 
  *
  *FileName:          LightModelTest.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-27
  *
  *Description:		LightModel和材料属性测试
**********************************************************************************/
#ifndef LightModelTest_h__
#define LightModelTest_h__

#include "LearnOpenGLBase.h"

class CLightModelTest : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CLightModelTest();
	~CLightModelTest(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // LightModelTest_h__
