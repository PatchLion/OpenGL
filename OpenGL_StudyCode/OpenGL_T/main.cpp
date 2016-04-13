/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <iostream>
#pragma comment (lib, "glew32.lib")
using namespace std;

#include "TestHeads.h"

int main(int argc, char** argv)
{
	return CURRENT_NAMESPACE::MainRun(argc, argv);
}




/*
int main(int argc, char** argv)
{
	//³õÊ¼»¯
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);

	if (argc >= 3)
	{
		glutInitContextVersion(atoi(argv[1]), atoi(argv[2]));
	}
	else
	{
		glutInitContextVersion(3, 0);
	}

	glutInitContextProfile(GLUT_CORE_PROFILE);
	int nRet = glutCreateWindow(argv[0]);
	cout << glGetString(GL_VERSION) << endl;
	cout << glGetString(GL_RENDERER) << endl;

	glewExperimental = GL_TRUE;
	if (glewInit())
	{
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(1);
	}

	GLenum error = glGetError();

	init();
	glutDisplayFunc(display);
	glutMainLoop();
	}
	*/