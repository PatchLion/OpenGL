/*********************************************************************************
  * 
  *
  *FileName:          DrawPixels8_3.h
  *
  *Author:         	   
  *
  *Date:         	       2016-5-1
  *
  *Description:		绘制位图
**********************************************************************************/
#ifndef DrawPixels8_3_h__
#define DrawPixels8_3_h__

#include "LearnOpenGLBase.h"

class CDrawPixels8_3 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawPixels8_3();
	~CDrawPixels8_3(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);


	void makeCheckImage();
};
#endif // DrawPixels8_3_h__
