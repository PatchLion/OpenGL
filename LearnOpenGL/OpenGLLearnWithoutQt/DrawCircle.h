/*********************************************************************************
  * 
  *
  *FileName:          DrawCircle.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		绘制正二十面体（加入法线向量）openGL编程指南第八版p74
**********************************************************************************/
#ifndef DrawCircle_h__
#define DrawCircle_h__

#include "LearnOpenGLBase.h"

class CDrawCircle : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawCircle();
	~CDrawCircle(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // DrawCircle_h__
