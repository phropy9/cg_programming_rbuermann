//Application.h
//////////////////////

//Standard Headers...

#pragma once

//#include <glew.h>
#include <GL\glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"


//Standard Headers...
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>




//Name Spaces...

using namespace std;
using namespace glm;

#define GLFW_DLL
#define APP_NAME "<<buermannRoman>>"
#define EXIT_WITH_ERROR -1
#define EXIT_WITH_SUCCESS 0
#define OPEN_GL_VERSION 3
#define ANTIALIASING 4
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define GLFW_FAIL  0
#define FIELD_OF_VIEW 45.0f
#define Z_NEAR 0.1f
#define Z_FAR 100.0f

extern GLFWwindow* window;
extern GLint shaderStatus;
extern bool activeRef;



//int Load();
//void Update();
//void Render();

//void CheckShaderStatus();
