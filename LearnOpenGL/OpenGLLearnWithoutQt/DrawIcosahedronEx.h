/*********************************************************************************
  * 
  *
  *FileName:          DrawIcosahedronEx.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		绘制正二十面体（加入法线向量）
**********************************************************************************/
#ifndef DrawIcosahedronEx_h__
#define DrawIcosahedronEx_h__

#include "LearnOpenGLBase.h"

class CDrawIcosahedronEx : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawIcosahedronEx();
	~CDrawIcosahedronEx(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // DrawIcosahedronEx_h__
