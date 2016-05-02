#include "stdafx.h"
#include "DrawPixels8_3.h"
#define checkImageWidth 64
#define checkImageHeight 64
GLubyte checkImage[checkImageWidth][checkImageHeight][3];

CDrawPixels8_3::CDrawPixels8_3()
{
}

CDrawPixels8_3::~CDrawPixels8_3()
{
}


void CDrawPixels8_3::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glRasterPos2i(0, 0);
	glDrawPixels(checkImageWidth, checkImageHeight, GL_RGB, GL_UNSIGNED_BYTE, checkImage);

	
	glutSwapBuffers();
}

void CDrawPixels8_3::init()
{
	CLearnOpenGLBase::init();

	makeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void CDrawPixels8_3::keyPressedEvent(unsigned char key, int x, int y)
{
	if ('o' == key)
	{
		//glReadPixels(0, 0, width(), height(), GL_UNSIGNED_INT_24_8, GL_RGB, )
	}
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CDrawPixels8_3::makeCheckImage()
{
	int i, j, c;

	for ( i = 0; i < checkImageHeight; i++)
	{
		for (j = 0; j < checkImageWidth; j++)
		{
			c = ((i & 0x8) == 0) ^ ((j & 0x8) == 0) * 255;
			checkImage[i][j][0] = (GLubyte)c;
			checkImage[i][j][1] = (GLubyte)c;
			checkImage[i][j][2] = (GLubyte)c;
		}
	}
}
