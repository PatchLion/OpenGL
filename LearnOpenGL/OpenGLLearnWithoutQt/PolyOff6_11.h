/*********************************************************************************
  * 
  *
  *FileName:          PolyOff6_11.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		消除不良视觉效果的多边形偏移
**********************************************************************************/
#ifndef PolyOff6_11_h__
#define PolyOff6_11_h__

#include "LearnOpenGLBase.h"

class CPolyOff6_11 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CPolyOff6_11();
	~CPolyOff6_11(); 

public:
	//初始化
	virtual void init();

	void drawSphere(double tx, double ty, double tz, bool isPolyGonOffset);

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // PolyOff6_11_h__
