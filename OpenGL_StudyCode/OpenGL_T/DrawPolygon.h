/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <iostream>

#pragma comment (lib, "glew32.lib")
using namespace std;


namespace DrawPolygon
{
	void showFunction(void)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);


		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_LINE);

		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		GLfloat points[4][2] = { { -0.8, -0.8 }, { 0.8, -0.8 }, { -0.6, 0.6 }, { -0.9, 0.5 } };
		glVertex2fv(points[0]);
		glVertex2fv(points[1]);
		glVertex2fv(points[2]);
		glVertex2fv(points[3]);
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
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);	//设置视口大小
		glLoadIdentity(); //将之前矩阵变换导致变化过的栈顶矩阵重新归位
		glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);	//平行修剪空间。这种投影意味着离观察者较远的对象看上去不会变小（与透视投影相反）
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}



	void keyboardFunc(unsigned char key, int x, int y)
	{
		printf("Press key: %d\n", key);
	}
	bool bFront = false;
	void mouseFunc(int button, int state, int x, int y)
	{
		printf("Mouse press: %d, %d at (%d, %d)\n", button, state, x, y);

		if (0 == state)
		{
			//切换多边形的正面和背面
			if (bFront)
			{
				glFrontFace(GL_CCW);
			}
			else
			{
				glFrontFace(GL_CW);
			}
			bFront = !bFront;
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

		//glDisable(GL_POINT_SMOOTH);//取消抗锯齿

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


		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK); //剔除背面


		glutKeyboardFunc(&keyboardFunc);
		glutMouseFunc(&mouseFunc);
		glutReshapeFunc(&reshapeFunc);
		glutIdleFunc(&idleFunc);
		glutDisplayFunc(&showFunction);		//必须在初始化成功后设置

		glutMainLoop();

		return 0;
	}
}
