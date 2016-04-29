/*********************************************************************************
  * 
  *
  *FileName:          PolyOff6_11.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		���������Ӿ�Ч���Ķ����ƫ��
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
	//��ʼ��
	virtual void init();

	void drawSphere(double tx, double ty, double tz, bool isPolyGonOffset);

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // PolyOff6_11_h__
