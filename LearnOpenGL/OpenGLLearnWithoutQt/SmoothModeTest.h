/*********************************************************************************
  * 
  *
  *FileName:          SmoothModeTest.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-27
  *
  *Description:		ƽ����ɫģ��
**********************************************************************************/
#ifndef SmoothModeTest_h__
#define SmoothModeTest_h__

#include "LearnOpenGLBase.h"
#include <vector>

class CSmoothModeTest : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CSmoothModeTest();
	~CSmoothModeTest(); 

public:
	//��ʼ��
	virtual void init();


protected:
	virtual void displayEvent();
};
#endif // SmoothModeTest_h__
