/*********************************************************************************
  * 
  *
  *FileName:          UnprojectTest.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-27
  *
  *Description:		坐标逆变换、模拟变换
**********************************************************************************/
#ifndef UnprojectTest_h__
#define UnprojectTest_h__

#include "LearnOpenGLBase.h"
#include <vector>

struct stVeritex3f
{
	stVeritex3f()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	stVeritex3f(GLfloat fx, GLfloat fy, GLfloat fz)
	{
		x = fx;
		y = fy;
		z = fz;
	}

	GLfloat x;
	GLfloat y;
	GLfloat z;
};

class CUnprojectTest : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CUnprojectTest();
	~CUnprojectTest(); 

public:
	//初始化
	virtual void init();


protected:
	virtual void displayEvent();
	virtual void mouseEvent(int button, int state, int x, int y);
	virtual void keyPressedEvent(unsigned char key, int x, int y);

protected:
	std::vector<stVeritex3f>  m_vecVeritex;
};
#endif // UnprojectTest_h__
