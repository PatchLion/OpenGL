/*********************************************************************************
  * 
  *
  *FileName:          DrawIcosahedron.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		绘制正二十面体
**********************************************************************************/
#ifndef DrawIcosahedron_h__
#define DrawIcosahedron_h__

#include "LearnOpenGLBase.h"

class CDrawIcosahedron : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawIcosahedron();
	~CDrawIcosahedron(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // DrawIcosahedron_h__
