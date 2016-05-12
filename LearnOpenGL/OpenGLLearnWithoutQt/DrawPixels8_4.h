/*********************************************************************************
  * 
  *
  *FileName:          DrawPixels8_4.h
  *
  *Author:         	   
  *
  *Date:         	       2016-5-3
  *
  *Description:		绘制、复制和缩放像素数据
**********************************************************************************/
#ifndef DrawPixels8_4_h__
#define DrawPixels8_4_h__

#include "LearnOpenGLBase.h"

class CDrawPixels8_4 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawPixels8_4();
	~CDrawPixels8_4(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
	virtual void mousePressedMoveEvent(int x, int y);

	void makeCheckImage();
};
#endif // DrawPixels8_4_h__
