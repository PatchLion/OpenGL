/*********************************************************************************
  * 
  *
  *FileName:          PrimrestartTest.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		����ͼԪ����
**********************************************************************************/
#ifndef PrimrestartTest_h__
#define PrimrestartTest_h__

#include "LearnOpenGLBase.h"

class CPrimrestartTest : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CPrimrestartTest();
	~CPrimrestartTest(); 

public:
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // PrimrestartTest_h__
