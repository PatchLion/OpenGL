/*********************************************************************************
  * 
  *
  *FileName:          BlendAlpha3D6_3.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-27
  *
  *Description:		��ά���
**********************************************************************************/
#ifndef BlendAlpha3D6_3_h__
#define BlendAlpha3D6_3_h__

#include "LearnOpenGLBase.h"

class CBlendAlpha3D6_3 : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CBlendAlpha3D6_3();
	~CBlendAlpha3D6_3(); 

public:
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // BlendAlpha3D6_3_h__
