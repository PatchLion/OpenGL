#ifndef LoadShaders_h__
#define LoadShaders_h__

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef struct {
	GLenum       type;
	const char*  filename;
	GLuint       shader;
} ShaderInfo;

GLuint LoadShaders(ShaderInfo*);
#endif // LoadShaders_h__