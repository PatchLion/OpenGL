#include "stdafx.h"
#include "DrawChecker9_1.h"
#define checkImageWidth 64
#define checkImageHeight 64
GLubyte checkImage_2[checkImageWidth][checkImageHeight][4];

static GLuint texName;

CDrawChecker9_1::CDrawChecker9_1()
{
}

CDrawChecker9_1::~CDrawChecker9_1()
{
}


void CDrawChecker9_1::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texName);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(2.41421, 1.0, -1.41421);
	glTexCoord2f(1.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
	glEnd();

	glutSwapBuffers();
	glDisable(GL_TEXTURE_2D);
}

void CDrawChecker9_1::init()
{
	CLearnOpenGLBase::init();

	makeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage_2);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void CDrawChecker9_1::keyPressedEvent(unsigned char key, int x, int y)
{
	
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CDrawChecker9_1::makeCheckImage()
{
	int i, j, c;

	for ( i = 0; i < checkImageHeight; i++)
	{
		for (j = 0; j < checkImageWidth; j++)
		{
			c = (((i & 0x8) == 0) ^ ((j & 0x8)) == 0) * 255;
			checkImage_2[i][j][0] = (GLubyte)c;
			checkImage_2[i][j][1] = (GLubyte)c;
			checkImage_2[i][j][2] = (GLubyte)c;
			checkImage_2[i][j][3] = (GLubyte)255;
		}
	}
}
