/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include "stdafx.h"

#pragma comment (lib, "glew32.lib")
using namespace std;

namespace Color3DObject
{
	bool bIsGreen = false;
	void showFunction(void)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glPushMatrix();
		gluLookAt(2, 2, 2, 0, 0, 0, 0, 1, 0);
		glTranslatef(-1.5f, -0.5f, -0.7f);
		glRotatef(0, 1.0f, 1.0f, 0.0f);
		glShadeModel(GL_FLAT);


		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0f, 1.8f, 0.0f);
		for (float angle = 0.0f; angle < 2.0f * GL_PI; angle += GL_PI/8.0f)
		{
			if (bIsGreen)
			{
				glColor3f(0.0f, 1.0f, 0.0f);
			}
			else
			{
				glColor3f(0.0f, 0.0f, 1.0f);
			}
			bIsGreen = !bIsGreen;

			glVertex3f(0.8 * sin(angle), 0.0f, 0.8*cos(angle));
		}
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
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); 
		gluPerspective(60, (double)w/(double)h, 1, 50);
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
		glutDisplayFunc(&showFunction);		//必须在初始化成功后设置

		glutMainLoop();

		return 0;
	}
}
