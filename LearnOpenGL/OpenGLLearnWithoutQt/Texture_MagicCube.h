/*********************************************************************************
  * 
  *
  *FileName:          Texture_MagicCube.h
  *
  *Author:         	   
  *
  *Date:         	       2016-5-16
  *
  *Description:		纹理贴图练习-魔方
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
	//初始化
	virtual void init();

protected:
	virtual void displayEvent();


private:
	GLuint  m_texture;  // 存储一个纹理
};
#endif // Texture_MagicCube_h__
