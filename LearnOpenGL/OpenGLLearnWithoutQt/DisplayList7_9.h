/*********************************************************************************
  * 
  *
  *FileName:          DisplayList7_9.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-30
  *
  *Description:		����ģʽ�������ʾ�б�
**********************************************************************************/
#ifndef DisplayList7_9_h__
#define DisplayList7_9_h__

#include "LearnOpenGLBase.h"


class CDisplayList7_9 : public LearnOpenGL::CLearnOpenGLBase
{

public:
	CDisplayList7_9();
	~CDisplayList7_9(); 

public:
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

private:
	GLuint m_offset;
};
#endif // DisplayList7_9_h__
