/*********************************************************************************
  * Copyright(C) 2009   ChengDu Everimaging
  *
  *FileName:          LearnOpenGLBase.h
  *
  *Author:         	   dai xiaobing
  *
  *Date:         	       2016-4-19
  *
  *Description:		OpenGL练习用基类
**********************************************************************************/
#ifndef LearnOpenGLBase_h__
#define LearnOpenGLBase_h__

#include "stdafx.h"

namespace LearnOpenGL
{

	class CLearnOpenGLBase
	{
	public:
		enum ProjectionType
		{
			Perspective,			
			Ortho,
			Ortho2D,
		};

	public:
		CLearnOpenGLBase(bool doubleBuffer = true);
		~CLearnOpenGLBase();

	public:
		//初始化
		virtual void init();
		 
		//注册为当前实例
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

		//是否显示坐标系
		bool isShowCoordinates() const  { return m_bShowCoor; }
		void setShowCoordinates(bool show);

		//计算视野
		double calculateAngle(double size, double distance);

		//
		bool isDoubleBuffer() const { return m_bIsDoubleBuffer; }

		//
		void flush();

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
		virtual void keyPressedEvent(unsigned char key, int x, int y);
		virtual void mouseWheelEvent(int button, int dir, int x, int y);

		//快捷参数值，通过0~9增加对应的值，Shift+0~9减少值（增加或减少都是按步长） 
		double value(int index) const;
		void setDefaultValue(int index, double value);
		double valueStep(int index) const;
		void setValueStep(int index, double step);
		void resetValueAndStepToDefault();
		void resetAllValue();

	public:
		static void s_display();
		static void s_idle();
		static void s_resize(int w, int h);
		static void s_mouse(int button, int state, int x, int y);
		static void s_mousePressedMove(int x, int y);
		static void s_mouseMove(int x, int y);
		static void s_keyPressed(unsigned char key, int x, int y);
		static void s_mouseWheel(int button, int dir, int x, int y);

	private:
		static CLearnOpenGLBase* current;

		bool							m_bShowCoor;
		int							m_currentWidth;
		int							m_currentHeight;
		ProjectionType			m_projectionType;

		int							m_yAngle;

		//快捷键0-9 代表的值和增减步长
		double			m_indexToDefaultValue[10];
		double			m_indexToValue[10];
		double			m_indexToStep[10];


		bool				m_bIsDoubleBuffer;//使用双缓存 默认：是
	};
}
#endif // LearnOpenGLBase_h__
