#include "Application.h"

#pragma once

class Quad {
public:
	GLuint ID;
	vec3 position, scaleVector;
	mat4 MVPMatrix;

	Quad();
	Quad (GLuint ID, vec3 position, vec3 scaleVector);
	void Draw(mat4 projectionMatrix, mat4 viewMatrix, GLuint MVPMatrixID);

};

GLuint& LoadQuad();
GLuint LoadBMP(const char * imagepath);


