/*********************************************************************************
  * 
  *
  *FileName:          VAO2_81.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		openGL���ָ�ϵڰ˰�2-18ʵ��
  
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
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
};
#endif // VAO2_81_h__
