#include "stdafx.h"
#include "Light5_7.h"

CLight5_7::CLight5_7()
{
	
}

CLight5_7::~CLight5_7()
{
}


static int spin = 0;
static GLdouble ex = 1.0, ey = 1.0, ez = 1.0;
static GLfloat position[] = { 0.0, 0.0, 0.0, 1.0 };

void CLight5_7::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glPushMatrix();
	//gluLookAt (ex, ey, ez, 0, 0, 0.0, 0.0, 1.0, 0.0); // ���۲��̶�����������ϵ��ԭ��ʱ,�������ִ˽����ԭ��
	gluLookAt(ex, ey, ez, ex, 0, 0.0, 0.0, 1.0, 0.0); //�����̵�w,s,a,d������Բ������������,��Ϊ�����ǽ��������ӵ�Ĺ������
	glRotated((GLdouble)spin, 1.0, 0.0, 0.0);
	glutSolidTorus(0.275, 0.85, 8, 15);
	glPopMatrix();

	glutSwapBuffers();
}



void CLight5_7::init()
{

	CLearnOpenGLBase::init();



	GLfloat white_light[] = { 1, 1, 1, 1 };
	GLfloat red_light[] = { 1, 0, 0, 1 };
	GLfloat blue_light[] = { 0, 0, 1, 0 };
	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };


	glLightfv(GL_LIGHT0, GL_DIFFUSE, blue_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);//�������� glLightfv�ƶ���Դλ�ã���Դ��Ĭ�Ϻ��ӵ㣨�۾�����һ��

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void CLight5_7::keyPressedEvent(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w': ey += 0.2;  glutPostRedisplay(); break;
	case 's': ey -= 0.2;  glutPostRedisplay(); break;
	case 'd': ex += 0.2;  glutPostRedisplay(); break;
	case 'a': ex -= 0.2;  glutPostRedisplay(); break;
	case 27:
		exit(0);
		break;
	}
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CLight5_7::resizeEvent(int w, int h)
{
	LearnOpenGL::CLearnOpenGLBase::resizeEvent(w, h);

}

void CLight5_7::mouseEvent(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			spin = (spin + 30) % 360;
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}

	LearnOpenGL::CLearnOpenGLBase::mouseEvent(button ,state, x, y);


}
