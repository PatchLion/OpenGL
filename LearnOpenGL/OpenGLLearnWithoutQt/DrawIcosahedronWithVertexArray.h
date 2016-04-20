/*********************************************************************************
  * 
  *
  *FileName:          DrawIcosahedronWithVertexArray.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		使用顶点数组绘制正二十面体
**********************************************************************************/
#ifndef DrawIcosahedronWithVertexArray_h__
#define DrawIcosahedronWithVertexArray_h__

#include "LearnOpenGLBase.h"

class CDrawIcosahedronWithVertexArray : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawIcosahedronWithVertexArray();
	~CDrawIcosahedronWithVertexArray(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // DrawIcosahedronWithVertexArray_h__
