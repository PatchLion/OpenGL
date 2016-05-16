#include "stdafx.h"

#include "TestHeads.h"
#include "Teapot.h"
int main(int argc, char** argv)
{

	printf("---------------默认快捷键(如果子类没有重定义的话)----------\n");
	printf("[ : 绕-y轴旋转坐标系\n");
	printf("] : 绕y轴旋转坐标系\n");
	printf("r : 重置坐标系角度\n");
	printf("s : 显示/隐藏坐标系\n");
	printf("q : 透视模式\n");
	printf("w : 正视模式\n");
	printf("e : 二维视图\n");
	printf("0~9 : 增加相应序号快捷值\n");
	printf("Shift+0~9 : 减少相应序号快捷值\n");
	printf("---------------------------------------------------------------------\n");

	glutInit(&argc, argv);

	glutInitWindowPosition(700, 200);
	glutInitWindowSize(500, 500);

	glutCreateWindow("PatchLion的OpenGL学习实例!");

	cout << glGetString(GL_VERSION) << endl;
	cout << glGetString(GL_RENDERER) << endl;

	if (GLEW_OK != glewInit())
	{
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(-1);
	}
	else
	{
		//实例化一个对象
		LearnOpenGL::CLearnOpenGLBase::registToCurrent<CURRENT_CLASS>();

		glutMotionFunc(&LearnOpenGL::CLearnOpenGLBase::s_mousePressedMove); 
		glutKeyboardFunc(&LearnOpenGL::CLearnOpenGLBase::s_keyPressed);
		glutMouseFunc(&LearnOpenGL::CLearnOpenGLBase::s_mouse);
		glutReshapeFunc(&LearnOpenGL::CLearnOpenGLBase::s_resize);
		glutIdleFunc(&LearnOpenGL::CLearnOpenGLBase::s_idle);
		glutDisplayFunc(&LearnOpenGL::CLearnOpenGLBase::s_display);
		glutPassiveMotionFunc(&LearnOpenGL::CLearnOpenGLBase::s_mouseMove);
		glutMouseWheelFunc(&LearnOpenGL::CLearnOpenGLBase::s_mouseWheel);
	}

	glutMainLoop();
	return 0;
}