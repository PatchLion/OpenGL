/*********************************************************************************
  * 
  *
  *FileName:          PointP6_10.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		雾化球体
**********************************************************************************/
#ifndef PointP6_10_h__
#define PointP6_10_h__

#include "LearnOpenGLBase.h"

class CPointP6_10 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CPointP6_10();
	~CPointP6_10(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // PointP6_10_h__
