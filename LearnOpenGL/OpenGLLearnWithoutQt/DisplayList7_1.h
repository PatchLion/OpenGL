/*********************************************************************************
  * 
  *
  *FileName:          DisplayList7_1.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		显示列表(3.1已废弃)
**********************************************************************************/
#ifndef DisplayList7_1_h__
#define DisplayList7_1_h__

#include "LearnOpenGLBase.h"

class CDisplayList7_1 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDisplayList7_1();
	~CDisplayList7_1(); 

public:
	//初始化
	virtual void init();

	void torus(int numc, int numt);

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

	GLuint theTorus;
};
#endif // DisplayList7_1_h__
