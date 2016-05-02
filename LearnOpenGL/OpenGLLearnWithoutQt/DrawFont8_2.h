/*********************************************************************************
  * 
  *
  *FileName:          DrawFont8_2.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		绘制完整的字体
**********************************************************************************/
#ifndef DrawFont8_2_h__
#define DrawFont8_2_h__

#include "LearnOpenGLBase.h"

class CDrawFont8_2 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawFont8_2();
	~CDrawFont8_2(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

	void makeRasterFont(void);

	void printString(char *s);
private:
	GLuint m_fontOffset;
};
#endif // DrawFont8_2_h__
