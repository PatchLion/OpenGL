/*********************************************************************************
  * 
  *
  *FileName:          SmoothModeTest.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-27
  *
  *Description:		平滑着色模型
**********************************************************************************/
#ifndef SmoothModeTest_h__
#define SmoothModeTest_h__

#include "LearnOpenGLBase.h"
#include <vector>

class CSmoothModeTest : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CSmoothModeTest();
	~CSmoothModeTest(); 

public:
	//初始化
	virtual void init();


protected:
	virtual void displayEvent();
};
#endif // SmoothModeTest_h__
