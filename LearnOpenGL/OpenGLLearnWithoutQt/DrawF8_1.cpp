#include "stdafx.h"
#include "DrawF8_1.h"

CDrawF8_1::CDrawF8_1()
{
}

CDrawF8_1::~CDrawF8_1()
{
}


void CDrawF8_1::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	GLubyte rasters[24] = {
		0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
		0xc0, 0x00, 0xc0, 0x00, 0xff, 0x00,
		0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00,
		0xc0, 0x00, 0xff, 0x00, 0xff, 0x00,
	};

	glBitmap(10, 12, 0.0, 0.0, 11, 0.0, rasters);
	glBitmap(10, 12, 0.0, 0.0, 11, 0.0, rasters);
	glBitmap(10, 12, 0.0, 0.0, 11, 0.0, rasters);


	glutSwapBuffers();
}

void CDrawF8_1::init()
{
	CLearnOpenGLBase::init();

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	//glRasterPos3i(0, 0, -2);
	glWindowPos3d(3, 3, 0);

	GLfloat pos[4];
	glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);

	printf("GL_CURRENT_RASTER_POSITION: %f, %f, %f, %f\n", pos[0], pos[1], pos[2], pos[3]);

	GLboolean vaild;
	glGetBooleanv(GL_CURRENT_RASTER_POSITION_VALID, &vaild);
	printf("GL_CURRENT_RASTER_POSITION_VALID: %s\n", vaild ? "true" : "false");
}

void CDrawF8_1::keyPressedEvent(unsigned char key, int x, int y)
{
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}
