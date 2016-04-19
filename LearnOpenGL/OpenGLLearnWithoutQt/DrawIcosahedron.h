#ifndef DrawIcosahedron_h__
#define DrawIcosahedron_h__

#include "LearnOpenGLBase.h"

class CDrawIcosahedron : public LearnOpenGL::CLearnOpenGLBase
{
public:
	CDrawIcosahedron();
	~CDrawIcosahedron(); 

protected:
	virtual void displayEvent();
};
#endif // DrawIcosahedron_h__
