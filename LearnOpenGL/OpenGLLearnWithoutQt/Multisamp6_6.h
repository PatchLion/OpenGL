/*********************************************************************************
  * 
  *
  *FileName:          Multisamp6_6.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		���ز���
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
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

private:
	bool m_bgToggle;
};
#endif // Multisamp6_6_h__
