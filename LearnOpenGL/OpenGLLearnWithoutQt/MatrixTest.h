/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include "stdafx.h"
#include <iostream>

#pragma comment (lib, "glew32.lib")
using namespace std;

double value = 0.5;

int matrixMode = 0; //0: Ortho 1: Frustum 2: gluPerspective
int currentWidth = 0;
int currentHeight = 0;

int g_x = 2, g_y = 2, g_z = 2;
namespace MatrixTest
{
	void resetProjectionMatrix(int type)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		switch (type)
		{
		case 0:
		{
			glOrtho(-3.75, 3.75, -3.75, 3.75, 1.0, 1000.0);
		}
		break;

		case 1:
		{
			glFrustum(-1.25, 1.25, -1.25, 1.25, 1.0, 1000.0);
		}
		break;

		case 2:
		{
			gluPerspective(180, (double)currentWidth / (double)currentHeight, 0, 1000);
		}
		break;
		}
	}

	void showFunction(void)
	{
		printf("g_x: %d\n", g_x);

		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(50, double(currentWidth) / double(currentHeight), 1.5, 50);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);
		glRotatef(g_x, 0, 1, 0);
		glLineWidth(3);

		//glutWireTeapot(2);
		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(0.0f, 0.0f, 0.0f); //���Ƶ�һ���߶�  
		glVertex3f(1.0f, 0.0f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0, 1, 0);
		glVertex3f(0.0f, 0.0f, 0.0f); //���Ƶڶ����߶�  
		glVertex3f(0.0f, 1.0f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0, 0, 1);
		glVertex3f(0.0f, 0.0f, 0.0f); //���Ƶ������߶�  
		glVertex3f(0.0f, 0.0f, 1.0f);
		glEnd();

		/*glPointSize(3);
		glBegin(GL_POINTS);
		glColor3f(1.0, 0, 0);
		glVertex3f(1, 1, 1); //���Ƶ�
		glEnd();*/

		glutSwapBuffers();
	}

	void idleFunc(void)
	{
		//printf("idle function!\n");
	}

	void reshapeFunc(int w, int h)
	{
		currentWidth = w;
		currentHeight = h;
		printf("Reshape: %d, %d\n", w, h);
		//resetProjectionMatrix(matrixMode);
		/*GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;
		if (w <= h)
			glOrtho(-100.0, 100.0, -100.0 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
		else
			glOrtho(-100.0*aspectRatio, 100.0*aspectRatio, -100.0, 100.0, 1.0, -1.0);*/
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);	//�����ӿڴ�С

	
	}

	void keyboardFunc(unsigned char key, int x, int y)
	{
		printf("Press key: %d\n", key);
		switch (key)
		{
		case 43: value += 0.1; break;  //+
		case 45: value -= 0.1; break;	//-
		case 48: matrixMode = 0; break;//0
		case 49: g_x += 1; break;//1
		case 50: g_x -= 1; break;//2
		default:
			break;
		}

		glutPostRedisplay();
	}
	void mouseFunc(int button, int state, int x, int y)
	{
		printf("Mouse press: %d, %d at (%d, %d)\n", button, state, x, y);
	}
	int MainRun(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		//glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);

		glutInitWindowPosition(700, 200);
		glutInitWindowSize(300, 300);

		//glDisable(GL_POINT_SMOOTH);//ȡ�������

		glutCreateWindow("PatchLion's first OpenGL windows!");

		cout << glGetString(GL_VERSION) << endl;
		cout << glGetString(GL_RENDERER) << endl;

		glShadeModel(GL_FLAT);
		glClearColor(0.0, 0.0, 0.0, 0.0);

		if (glewInit())
		{
			cerr << "Unable to initialize GLEW ... exiting" << endl;
			exit(1);
		}

		//��ѯδ���п���ݴ����������С�����Ŀ�ȷ�Χ
		GLfloat value[2];
		glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, value);

		printf("GL_ALIASED_LINE_WIDTH_RANGE: (%d - %d)\n", value[0], value[1]);

		glGetFloatv(GL_SMOOTH_LINE_WIDTH_RANGE, value);

		printf("GL_SMOOTH_LINE_WIDTH_RANGE: (%d - %d)\n", value[0], value[1]);

		glutKeyboardFunc(&keyboardFunc);
		glutMouseFunc(&mouseFunc);
		glutReshapeFunc(&reshapeFunc);
		glutIdleFunc(&idleFunc);
		glutDisplayFunc(&showFunction);		//�����ڳ�ʼ���ɹ�������

		glutMainLoop();
		return 0;
	}
}
