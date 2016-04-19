/*********************************************************************************
  * Copyright(C) 2009   ChengDu Everimaging
  *
  *FileName:          LearnOpenGLBase.h
  *
  *Author:         	   dai xiaobing
  *
  *Date:         	       2016-4-19
  *
  *Description:		OpenGL��ϰ�û���
**********************************************************************************/
#ifndef LearnOpenGLBase_h__
#define LearnOpenGLBase_h__

#include "stdafx.h"

namespace LearnOpenGL
{

	class CLearnOpenGLBase
	{
	public:
		enum OperationType
		{
			RotateX,
			RotateY,
			RotateZ,
			ScaleX,
			ScaleY,
			ScaleZ,
			TransX,
			TransY,
			TransZ,
		};

		enum ProjectionType
		{
			Perspective,			
			Ortho,
			Ortho2D,
		};

	public:
		CLearnOpenGLBase();
		~CLearnOpenGLBase();

	public:
		//��ʼ��
		virtual void init();
		 
		//ע��Ϊ��ǰʵ��
		template<class T>
		static void registToCurrent()
		{
			if (CLearnOpenGLBase::current)
			{
				delete CLearnOpenGLBase::current;
				CLearnOpenGLBase::current = 0;
			}
			CLearnOpenGLBase::current = new T;
			current->init();
		}
	protected:
		ProjectionType projectionType() const { return m_projectionType; }
		void changeProjectionType(ProjectionType val);

		int width() const { return m_currentWidth; }
		int height() const { return m_currentHeight; }

	protected:
		virtual void displayEvent();
		virtual void idleEvent() {}
		virtual void resizeEvent(int w, int h);
		virtual void mouseEvent(int button, int state, int x, int y){}
		virtual void mousePressedMoveEvent(int x, int y){}
		virtual void mouseMoveEvent(int x, int y){}
		virtual void keyPressedEvent(unsigned char key, int x, int y){}

	public:
		static void s_display();
		static void s_idle();
		static void s_resize(int w, int h);
		static void s_mouse(int button, int state, int x, int y);
		static void s_mousePressedMove(int x, int y);
		static void s_mouseMove(int x, int y);
		static void s_keyPressed(unsigned char key, int x, int y);

	private:
		static CLearnOpenGLBase* current;
		int m_currentWidth, m_currentHeight;
		ProjectionType			m_projectionType;
	};
}
#endif // LearnOpenGLBase_h__