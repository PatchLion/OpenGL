/*********************************************************************************
  * 
  *
  *FileName:          AargbPolygon.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-28
  *
  *Description:		RGBAģʽ�µĶ���ο����
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
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void keyPressedEvent(unsigned char key, int x, int y);
};
#endif // AargbPolygon_h__
