/*********************************************************************************
  * 
  *
  *FileName:          VAO2_81.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		openGL编程指南第八版2-18实例
  
**********************************************************************************/
#ifndef VAO2_81_h__
#define VAO2_81_h__

#include "LearnOpenGLBase.h"

class CVAO2_81 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CVAO2_81();
	~CVAO2_81(); 

public:
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // VAO2_81_h__
