/*********************************************************************************
  * 
  *
  *FileName:          DrawIcosahedronEx.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		��������ʮ���壨���뷨��������
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
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // DrawIcosahedronEx_h__
