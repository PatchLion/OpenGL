/*********************************************************************************
  * 
  *
  *FileName:          DrawIcosahedronWithVertexArray.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		ʹ�ö��������������ʮ����
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
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // DrawIcosahedronWithVertexArray_h__
