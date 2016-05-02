/*********************************************************************************
  * 
  *
  *FileName:          HierarchicalDisplayList7_3.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		层次显示列表 7-4
**********************************************************************************/
#ifndef HierarchicalDisplayList7_3_h__
#define HierarchicalDisplayList7_3_h__

#include "LearnOpenGLBase.h"

#define PT 1
#define STROKE 2
#define END 3
typedef struct charpoint
{
	GLfloat x, y;
	int type;
}CP;

class CHierarchicalDisplayList7_3 : public LearnOpenGL::CLearnOpenGLBase
{

public:
	CHierarchicalDisplayList7_3();
	~CHierarchicalDisplayList7_3(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);

	void initStrokedFont();

	void drawLetter(CP *l);

	void printStrokedString(char *s);
};
#endif // HierarchicalDisplayList7_3_h__
