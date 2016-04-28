/*********************************************************************************
  * 
  *
  *FileName:          Aaindex6_5.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		颜色索引模式下的抗锯齿
**********************************************************************************/
#ifndef Aaindex6_5_h__
#define Aaindex6_5_h__

#include "LearnOpenGLBase.h"

class CAaindex6_5 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CAaindex6_5();
	~CAaindex6_5(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // Aaindex6_5_h__
