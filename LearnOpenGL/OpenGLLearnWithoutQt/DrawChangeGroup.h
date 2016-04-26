/*********************************************************************************
  * 
  *
  *FileName:          DrawChangeGroup.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-26
  *
  *Description:		组合变换
  
**********************************************************************************/
#ifndef DrawChangeGroup_h__
#define DrawChangeGroup_h__

#include "LearnOpenGLBase.h"

class CDrawChangeGroup : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawChangeGroup();
	~CDrawChangeGroup(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void idleEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

private:
	void drawEarth();
	void drawRobotArm();

private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
	int m_nHour;
};
#endif // DrawChangeGroup_h__
