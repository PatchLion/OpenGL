/*********************************************************************************
  * 
  *
  *FileName:          DrawF8_1.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		����λͼ��F��
**********************************************************************************/
#ifndef DrawF8_1_h__
#define DrawF8_1_h__

#include "LearnOpenGLBase.h"

class CDrawF8_1 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawF8_1();
	~CDrawF8_1(); 

public:
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // DrawF8_1_h__
