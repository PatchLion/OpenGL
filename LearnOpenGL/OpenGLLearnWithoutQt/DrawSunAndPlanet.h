/*********************************************************************************
  * 
  *
  *FileName:          DrawSunAndPlanet.h
  *
  *Author:         	   
  *
  *Date:         	       2016-4-20
  *
  *Description:		ģ��̫��������
  
**********************************************************************************/
#ifndef DrawSunAndPlanet_h__
#define DrawSunAndPlanet_h__

#include "LearnOpenGLBase.h"

class CDrawSunAndPlanet : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawSunAndPlanet();
	~CDrawSunAndPlanet(); 

public:
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();
	virtual void idleEvent();

private:
	int m_nYear;
	int m_nDay;
};
#endif // DrawSunAndPlanet_h__
