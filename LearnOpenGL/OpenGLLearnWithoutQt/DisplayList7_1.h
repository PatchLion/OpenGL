/*********************************************************************************
  * 
  *
  *FileName:          DisplayList7_1.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		��ʾ�б�(3.1�ѷ���)
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
	//��ʼ��
	virtual void init();

	void torus(int numc, int numt);

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

	GLuint theTorus;
};
#endif // DisplayList7_1_h__
