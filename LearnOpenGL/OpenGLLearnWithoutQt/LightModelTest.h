/*********************************************************************************
  * 
  *
  *FileName:          LightModelTest.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-27
  *
  *Description:		LightModel�Ͳ������Բ���
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
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // LightModelTest_h__
