#include "stdafx.h"
#include "LightModelTest.h"

CLightModelTest::CLightModelTest()
{
	/*setDefaultValue(1, 0.1);
	setDefaultValue(2, 0.5);
	setDefaultValue(3, 0.8);
	setDefaultValue(4, 1.0);
	setValueStep(1, 0.1);
	setValueStep(2, 0.1);
	setValueStep(3, 0.1);
	setValueStep(4, 0.1);

	setDefaultValue(6, 0.1);
	setDefaultValue(7, 0.1);
	setDefaultValue(8, 0.1);
	setDefaultValue(9, 0.1);
	setValueStep(6, 0.1);
	setValueStep(7, 0.1);
	setValueStep(8, 0.1);
	setValueStep(9, 0.1);

	setDefaultValue(5, 5.0);*/
}

CLightModelTest::~CLightModelTest()
{
}

void CLightModelTest::displayEvent()
{
	glDisable(GL_LIGHTING);

	CLearnOpenGLBase::displayEvent();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
	GLfloat mat_speculer[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat no_shininess[] = { 0.0 };
	GLfloat low_shininess[] = {5};
	GLfloat high_shininess[] = { 100 };
	GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	//1
	glPushMatrix();
	glTranslatef(0.3, 0.5, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(0.2, 16, 16);

	GLdouble eqn[4] = { 1.0, 0.0, 1.0, 0.0 };
	GLdouble eqn2[4] = { 1.0, 1.0, 0.0, 0.0 };
	/*clip lower half --y<0*/
	glClipPlane(GL_CLIP_PLANE0, eqn);
	glEnable(GL_CLIP_PLANE0);
	/*clip left half --x<0*/
	glClipPlane(GL_CLIP_PLANE1, eqn2);
	glEnable(GL_CLIP_PLANE1);

	glPopMatrix();

	//2
	glPushMatrix();
	glTranslatef(0.7, 0.5, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_speculer);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();

	//3
	glPushMatrix();
	glTranslatef(1.1, 0.5, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_speculer);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();

	//4
	glPushMatrix();
	glTranslatef(1.5, 0.5, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();

	//5 Color Material
	glPushMatrix();
	glTranslatef(1.9, 0.5, 0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glColor3f(1.0, 0.0, 0.2);
	glutSolidSphere(0.2, 16, 16);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();
	glutSwapBuffers();
}



void CLightModelTest::init()
{

	CLearnOpenGLBase::init();



	GLfloat lmodel_ambient[] = { 1.0, 0.1, 0.1, 1.0 };


	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);//Æô¶¯Ë«Ãæ¹âÕÕ


	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

}
