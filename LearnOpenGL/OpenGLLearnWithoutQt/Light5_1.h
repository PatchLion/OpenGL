/*********************************************************************************
  * 
  *
  *FileName:          Light5_1.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-27
  *
  *Description:		光照球体
**********************************************************************************/
#ifndef Light5_1_h__
#define Light5_1_h__

#include "LearnOpenGLBase.h"

class CLight5_1 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CLight5_1();
	~CLight5_1(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

	virtual void idleEvent();

};
#endif // Light5_1_h__
