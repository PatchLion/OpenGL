/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <iostream>

#pragma comment (lib, "glew32.lib")
using namespace std;

namespace RunWithAnimation
{
	double spin = 0.0;
	void showFunction(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();
		glRotatef(spin, 0.0, 0.0, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		glRectf(-0.5, -0.5, 0.5, 0.5);
		glPopMatrix();
		glutSwapBuffers();
	}

	void idleFunc(void)
	{
		//printf("idle function!\n");
	}

	void reshapeFunc(int w, int h)
	{
		printf("Reshape: %d, %d\n", w, h);
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);	//�����ӿڴ�С
		glLoadIdentity(); //��֮ǰ����任���±仯����ջ���������¹�λ
		glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);	//ƽ���޼��ռ䡣����ͶӰ��ζ����۲��߽�Զ�Ķ�����ȥ�����С����͸��ͶӰ�෴��
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}


	void spinDisplay(void)
	{
		spin = spin + 2.0;
		if (spin > 360.0)
		{
			spin = spin - 360.0;
		}

		glutPostRedisplay();
	}

	void keyboardFunc(unsigned char key, int x, int y)
	{
		printf("Press key: %d\n", key);
	}
	void mouseFunc(int button, int state, int x, int y)
	{
		printf("Mouse press: %d, %d at (%d, %d)\n", button, state, x, y);

		switch (button)
		{
		case GLUT_LEFT_BUTTON:
		{
			if (GLUT_DOWN == state)
			{
				glutIdleFunc(&spinDisplay);
			}
		}
		break;

		case GLUT_RIGHT_BUTTON:
		{
			if (GLUT_DOWN == state)
			{
				glutIdleFunc(NULL);
			}
		}
		break;

		default:
			break;
		}
	}
	int MainRun(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

		glutInitWindowPosition(600, 600);
		glutInitWindowSize(300, 300);


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

		glutKeyboardFunc(&keyboardFunc);
		glutMouseFunc(&mouseFunc);
		glutReshapeFunc(&reshapeFunc);
		glutIdleFunc(&idleFunc);
		glutDisplayFunc(&showFunction);		//�����ڳ�ʼ���ɹ�������

		glutMainLoop();

		return 0;
	}
}
