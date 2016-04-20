#include "stdafx.h"

#include "TestHeads.h"

int main(int argc, char** argv)
{
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowPosition(700, 200);
	glutInitWindowSize(500, 500);

	glutCreateWindow("PatchLion��OpenGLѧϰʵ��!");

	cout << glGetString(GL_VERSION) << endl;
	cout << glGetString(GL_RENDERER) << endl;

	glClearColor(0.0, 0.0, 0.0, 0.0);

	if (GLEW_OK != glewInit())
	{
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(-1);
	}
	else
	{
		//ʵ����һ������
		LearnOpenGL::CLearnOpenGLBase::registToCurrent<CURRENT_CLASS>();

		glutMotionFunc(&LearnOpenGL::CLearnOpenGLBase::s_mousePressedMove);
		glutKeyboardFunc(&LearnOpenGL::CLearnOpenGLBase::s_keyPressed);
		glutMouseFunc(&LearnOpenGL::CLearnOpenGLBase::s_mouse);
		glutReshapeFunc(&LearnOpenGL::CLearnOpenGLBase::s_resize);
		glutIdleFunc(&LearnOpenGL::CLearnOpenGLBase::s_idle);
		glutDisplayFunc(&LearnOpenGL::CLearnOpenGLBase::s_display);
		glutPassiveMotionFunc(&LearnOpenGL::CLearnOpenGLBase::s_mouseMove);
	}

	glutMainLoop();
	return 0;
}