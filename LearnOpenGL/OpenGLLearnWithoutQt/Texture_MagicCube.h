/*********************************************************************************
  * 
  *
  *FileName:          Texture_MagicCube.h
  *
  *Author:         	   
  *
  *Date:         	       2016-5-16
  *
  *Description:		������ͼ��ϰ-ħ��
**********************************************************************************/
#ifndef Texture_MagicCube_h__
#define Texture_MagicCube_h__

#include "LearnOpenGLBase.h"
#include "stdafx.h"

class CTexture_MagicCube : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CTexture_MagicCube();
	~CTexture_MagicCube(); 

public:
	//��ʼ��
	virtual void init();

protected:
	virtual void displayEvent();


private:
	GLuint  m_texture;  // �洢һ������
};
#endif // Texture_MagicCube_h__
