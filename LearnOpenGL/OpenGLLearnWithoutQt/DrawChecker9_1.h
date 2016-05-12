/*********************************************************************************
  * 
  *
  *FileName:          DrawChecker9_1.h
  *
  *Author:         	   
  *
  *Date:         	       2016-5-1
  *
  *Description:		经过纹理贴图的棋盘
**********************************************************************************/
#ifndef DrawChecker9_1_h__
#define DrawChecker9_1_h__

#include "LearnOpenGLBase.h"

class CDrawChecker9_1 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawChecker9_1();
	~CDrawChecker9_1(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);


	void makeCheckImage();
};
#endif // DrawChecker9_1_h__
