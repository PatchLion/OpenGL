/*********************************************************************************
  * 
  *
  *FileName:          DrawCircle.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		��������ʮ���壨���뷨��������openGL���ָ�ϵڰ˰�p74
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
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // DrawCircle_h__
