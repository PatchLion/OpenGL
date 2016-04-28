/*********************************************************************************
  * 
  *
  *FileName:          Multisamp6_6.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		多重采样
**********************************************************************************/
#ifndef Multisamp6_6_h__
#define Multisamp6_6_h__

#include "LearnOpenGLBase.h"

class CMultisamp6_6 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CMultisamp6_6();
	~CMultisamp6_6(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

private:
	bool m_bgToggle;
};
#endif // Multisamp6_6_h__
