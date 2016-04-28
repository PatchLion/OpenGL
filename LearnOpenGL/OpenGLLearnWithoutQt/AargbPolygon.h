/*********************************************************************************
  * 
  *
  *FileName:          AargbPolygon.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		RGBA模式下的多边形抗锯齿
**********************************************************************************/
#ifndef AargbPolygon_h__
#define AargbPolygon_h__

#include "LearnOpenGLBase.h"

class CAargbPolygon : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CAargbPolygon();
	~CAargbPolygon(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // AargbPolygon_h__
