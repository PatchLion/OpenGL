/*********************************************************************************
  * 
  *
  *FileName:          DrawCilp3_5.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-26
  *
  *Description:		剪切平面 3.5例子
  
**********************************************************************************/
#ifndef DrawCilp3_5_h__
#define DrawCilp3_5_h__

#include "LearnOpenGLBase.h"

class CDrawCilp3_5 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawCilp3_5();
	~CDrawCilp3_5(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	//virtual void idleEvent();
};
#endif // DrawCilp3_5_h__
