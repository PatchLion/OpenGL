/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <iostream>

#pragma comment (lib, "glew32.lib")
using namespace std;

namespace DrawPoint
{
	void showFunction(void)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);


		glPointSize(10.0);

		glBegin(GL_POINTS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(0, 0);
		glEnd();

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



	void keyboardFunc(unsigned char key, int x, int y)
	{
		printf("Press key: %d\n", key);
	}
	void mouseFunc(int button, int state, int x, int y)
	{
		printf("Mouse press: %d, %d at (%d, %d)\n", button, state, x, y);
	}
	int MainRun(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

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

		//��ѯδ���п���ݴ����������С�����ĵ�
		GLfloat value[2];
		glGetFloatv(GL_ALIASED_POINT_SIZE_RANGE, value);

		printf("GL_ALIASED_POINT_SIZE_RANGE: (%d - %d)\n", value[0], value[1]);
		
		glGetFloatv(GL_SMOOTH_POINT_SIZE_RANGE, value);

		printf("GL_SMOOTH_POINT_SIZE_RANGE: (%d - %d)\n", value[0], value[1]);

		glutKeyboardFunc(&keyboardFunc);
		glutMouseFunc(&mouseFunc);
		glutReshapeFunc(&reshapeFunc);
		glutIdleFunc(&idleFunc);
		glutDisplayFunc(&showFunction);		//�����ڳ�ʼ���ɹ�������

		glutMainLoop();

		return 0;
	}
}
