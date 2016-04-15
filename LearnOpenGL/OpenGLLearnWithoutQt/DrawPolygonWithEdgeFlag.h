/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include "stdafx.h"
#include <iostream>

#pragma comment (lib, "glew32.lib")
using namespace std;

//����α߽��
namespace DrawPolygonWithEdgeFlag
{

	bool show = false;
	void showFunction(void)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_POLYGON);
		glEdgeFlag(GL_TRUE);
		glVertex2d(150, 160);
		glEdgeFlag(show ? GL_TRUE : GL_FALSE);
		glVertex2d(70, 290);
		glEdgeFlag(GL_TRUE);
		glVertex2d(55, 80);
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
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); //��֮ǰ����任���±仯����ջ���������¹�λ
		gluOrtho2D(0, w, 0, h);	
	}



	void keyboardFunc(unsigned char key, int x, int y)
	{
		printf("Press key: %d\n", key);
	}

	void mouseFunc(int button, int state, int x, int y)
	{
		printf("Mouse press: %d, %d at (%d, %d)\n", button, state, x, y);

		if (0 == state)
		{
			show = !show;
			glutPostRedisplay();
		}
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


		//glEnable(GL_CULL_FACE);
		//glCullFace(GL_BACK); //�޳�����


		glutKeyboardFunc(&keyboardFunc);
		glutMouseFunc(&mouseFunc);
		glutReshapeFunc(&reshapeFunc);
		glutIdleFunc(&idleFunc);
		glutDisplayFunc(&showFunction);		//�����ڳ�ʼ���ɹ�������

		glutMainLoop();

		return 0;
	}
}
