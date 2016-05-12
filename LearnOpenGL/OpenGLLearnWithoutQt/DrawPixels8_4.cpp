#include "stdafx.h"
#include "DrawPixels8_4.h"
#define checkImageWidth 64
#define checkImageHeight 64
GLubyte checkImage2[checkImageWidth][checkImageHeight][3];

static GLdouble zoomFactor = 1.0;


CDrawPixels8_4::CDrawPixels8_4()
	: LearnOpenGL::CLearnOpenGLBase(false)
{
}

CDrawPixels8_4::~CDrawPixels8_4()
{
}


void CDrawPixels8_4::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glRasterPos2i(0, 0);
	glDrawPixels(checkImageWidth, checkImageHeight, GL_RGB, GL_UNSIGNED_BYTE, checkImage2);

	flush();
}

void CDrawPixels8_4::init()
{
	CLearnOpenGLBase::init();

	makeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void CDrawPixels8_4::keyPressedEvent(unsigned char key, int x, int y)
{
	if ('o' == key)
	{
		//glReadPixels(0, 0, width(), height(), GL_UNSIGNED_INT_24_8, GL_RGB, )
	}
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CDrawPixels8_4::makeCheckImage()
{
	int i, j, c;

	for ( i = 0; i < checkImageHeight; i++)
	{
		for (j = 0; j < checkImageWidth; j++)
		{
			c = ((i & 0x8) == 0) ^ ((j & 0x8) == 0) * 255;
			checkImage2[i][j][0] = (GLubyte)c;
			checkImage2[i][j][1] = (GLubyte)c;
			checkImage2[i][j][2] = (GLubyte)c;
		}
	}
}

void CDrawPixels8_4::mousePressedMoveEvent(int x, int y)
{
	static GLint screeny;
	screeny = height() - (GLint)y;
	glRasterPos2i(x, screeny);
	glPixelZoom(zoomFactor,zoomFactor);
	glCopyPixels(0, 0, checkImageWidth, checkImageHeight, GL_COLOR);
	glPixelZoom(1.0, 1.0);
	glutPostRedisplay();
}
