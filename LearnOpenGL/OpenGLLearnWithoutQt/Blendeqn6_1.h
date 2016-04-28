/*********************************************************************************
  * 
  *
  *FileName:          Blendeqn6_1.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-27
  *
  *Description:		混合方程式模式
**********************************************************************************/
#ifndef Blendeqn6_1_h__
#define Blendeqn6_1_h__

#include "LearnOpenGLBase.h"

class CBlendeqn6_1 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CBlendeqn6_1();
	~CBlendeqn6_1(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

	virtual void idleEvent();

	static void drawLeftTriangle(void);
	static void drawRightTriangle(void);
private:
	bool m_bIsLeftFirst;
};
#endif // Blendeqn6_1_h__
