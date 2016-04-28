/*********************************************************************************
  * 
  *
  *FileName:          Aargb6_4.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		RGBA模式下的抗锯齿
**********************************************************************************/
#ifndef Aargb6_4_h__
#define Aargb6_4_h__

#include "LearnOpenGLBase.h"

class CAargb6_4 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CAargb6_4();
	~CAargb6_4(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // Aargb6_4_h__
