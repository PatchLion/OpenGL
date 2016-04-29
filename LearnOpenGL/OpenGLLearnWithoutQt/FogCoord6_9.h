/*********************************************************************************
  * 
  *
  *FileName:          FogCoord6_9.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		雾化坐标
**********************************************************************************/
#ifndef FogCoord6_9_h__
#define FogCoord6_9_h__

#include "LearnOpenGLBase.h"

class CFogCoord6_9 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CFogCoord6_9();
	~CFogCoord6_9(); 

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
#endif // FogCoord6_9_h__
