/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include "stdafx.h"

#pragma comment (lib, "glew32.lib")
using namespace std;


namespace StatusManage
{
	void showFunction(void)
	{

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
		glClearColor(0.0, 1.0, 0.0, 0.0);

		if (glewInit())
		{
			cerr << "Unable to initialize GLEW ... exiting" << endl;
			exit(1);
		}

		glEnable(GL_DEPTH_TEST);
		GLboolean enable = glIsEnabled(GL_DEPTH_TEST);

		printf("GL_DEPTH_TEST enabled: %d\n", enable);

		glDisable(GL_DEPTH_TEST);
		enable = glIsEnabled(GL_DEPTH_TEST);

		printf("GL_DEPTH_TEST enabled: %d\n", enable);


		GLdouble colors[3];
		glGetDoublev(GL_CURRENT_COLOR, colors);

		printf("GL_CURRENT_COLOR: (%d, %d, %d)", colors[0], colors[1], colors[2]);

		glutDisplayFunc(&showFunction);		//必须在初始化成功后设置

		glutMainLoop();

		return 0;
	}
}
