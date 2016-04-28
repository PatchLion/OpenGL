/*********************************************************************************
  * 
  *
  *FileName:          Fog6_7.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		雾化球体
**********************************************************************************/
#ifndef Fog6_7_h__
#define Fog6_7_h__

#include "LearnOpenGLBase.h"

class CFog6_7 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CFog6_7();
	~CFog6_7(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

	void renderSphere(GLfloat x, GLfloat y, GLfloat z);
private:
	GLint m_efogMode;
};
#endif // Fog6_7_h__
