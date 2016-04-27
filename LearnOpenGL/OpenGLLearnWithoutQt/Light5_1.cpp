#include "stdafx.h"
#include "Light5_1.h"

CLight5_1::CLight5_1()
{
	
}

CLight5_1::~CLight5_1()
{
}
GLfloat g_value = 0;
GLfloat g_value2 = 0;
GLfloat mat_specular[] = { 1, 1, 1, 1 };
GLfloat mat_shininess[] = { 50 };

GLfloat light_position[] = { 2, 0.1, 0, 0 };
GLfloat light_position_spot[] = { 0, 0.1, 1.1, 0 };
GLfloat light_direction_spot[] = { 0,0, -1, 0 };
GLfloat white_light[] = { 1, 1, 1, 1 };
GLfloat red_light[] = { 1, 0, 0, 1 };
GLfloat blue_light[] = { 0, 0, 1, 0 };
GLfloat lightblue_light[] = { 0, 0, 0.9, 0 };
GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };


void CLight5_1::displayEvent()
{
	CLearnOpenGLBase::displayEvent();


	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, white_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, blue_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 2);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	printf("Current vlaue: %f\n", 45);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position_spot);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_direction_spot);
	glLightfv(GL_LIGHT1, GL_SPECULAR, blue_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glPushMatrix();

	glRotated(g_value, 0.0, 1.0, 0);
	glutSolidSphere(1, 40, 32);

	glPopMatrix();


	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);

	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(light_position[0], light_position[1], light_position[2]);
	glVertex3f(light_position_spot[0], light_position_spot[1], light_position_spot[2]);
	glEnd();


	glutSwapBuffers();
}

void CLight5_1::init()
{
	CLearnOpenGLBase::init();

}

void CLight5_1::keyPressedEvent(unsigned char key, int x, int y)
{
	if (43 == key)//[
	{
		g_value += 1;
	}
	else if (45 == key)//]
	{
		g_value -= 1;
	}

	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CLight5_1::idleEvent()
{
	g_value = (((int)g_value + 1) % 360);
	g_value2 = g_value2 + 0.0001;
	Sleep(10);

	glutPostRedisplay();
}
