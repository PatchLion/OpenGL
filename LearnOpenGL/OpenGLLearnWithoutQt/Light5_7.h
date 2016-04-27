/*********************************************************************************
  * 
  *
  *FileName:          Light5_7.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-27
  *
  *Description:		光源与观察者一起动
**********************************************************************************/
#ifndef Light5_7_h__
#define Light5_7_h__

#include "LearnOpenGLBase.h"

class CLight5_7 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CLight5_7();
	~CLight5_7(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void resizeEvent(int w, int h);
	virtual void displayEvent();
	virtual void mouseEvent(int button, int state, int x, int y);
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // Light5_7_h__
