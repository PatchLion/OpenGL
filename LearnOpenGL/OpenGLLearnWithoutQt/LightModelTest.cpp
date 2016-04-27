#include "stdafx.h"
#include "LightModelTest.h"

CLightModelTest::CLightModelTest()
{
	setValue(1, 0.1);
	setValue(2, 0.5);
	setValue(3, 0.8);
	setValue(4, 1.0);
	setValueStep(1, 0.1);
	setValueStep(2, 0.1);
	setValueStep(3, 0.1);
	setValueStep(4, 0.1);

	setValue(6, 1.0);
	setValue(7, 1.0);
	setValue(8, 1.0);
	setValue(9, 1.0);
	setValueStep(6, 0.1);
	setValueStep(7, 0.1);
	setValueStep(8, 0.1);
	setValueStep(9, 0.1);

	setValue(5, 5.0);
}

CLightModelTest::~CLightModelTest()
{
}


static int spin = 0;
static GLdouble ex = 1.0, ey = 1.0, ez = 1.0;
static GLfloat position[] = { 0.0, 0.0, 0.0, 1.0 };


void CLightModelTest::displayEvent()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);


	GLfloat mat_amb_diff[] = { value(1), value(2), value(3), value(4) };
	GLfloat mat_specular[] = { value(6), value(7), value(8), value(9) };
	GLfloat low_shininess[] = { value(5) };
	CLearnOpenGLBase::displayEvent();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);

	glutSolidTorus(0.275, 0.85, 8, 15);
	glPopMatrix();

	glutSwapBuffers();
}



void CLightModelTest::init()
{

	CLearnOpenGLBase::init();


	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };


	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);//Æô¶¯Ë«Ãæ¹âÕÕ

}
