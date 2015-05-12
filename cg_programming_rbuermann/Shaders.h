#include "Application.h"

#pragma once

GLuint LoadShaders(const char *vertex_file_path, const char *fragment_file_path);
GLuint& LoadColor();
void RenderColor(GLuint colorBuffer);

