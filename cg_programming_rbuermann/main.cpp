//main.cpp..........
///////////////////////

#include "Application.h"
#include "Quad.h"
#include "Init.h"
#include "Shaders.h"

int main() {

	if(InitWindowFailed() | InitGlewFailed()) {

		return EXIT_WITH_ERROR;

	}

	GLuint vertexArrayID = 0;
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	//Create and compile glsl program from shaders...
	GLuint programID = LoadShaders("BasicVertexShader.vertexshader", "BasicFragmentShader.fragmentshader");

	//GLuint triangleID = LoadTriangle();
	//GLuint quadID = Quad::Draw();
	float aspectRatio = SCREEN_WIDTH / (float)SCREEN_HEIGHT;

	mat4 projectionMatrix = perspective(FIELD_OF_VIEW, aspectRatio, Z_NEAR, Z_FAR);

	GLuint MVPMatrixID = glGetUniformLocation(programID, "MVP");

	GLuint colorID = LoadColor();

	Quad quad1 = Quad(LoadQuad(), vec3(0.5f, 0.5f, 0.0f), vec3(1.0f, 1.0f, 0.0f));

	do {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);

		mat4 viewMatrix = lookAt(
			vec3 (0,0,3),
			vec3 (0,0,0),
			vec3 (0,1,0)
			);
		RenderColor(colorID);
		quad1.Draw(projectionMatrix, viewMatrix, MVPMatrixID);
		glfwSwapBuffers(window);
		glfwPollEvents();

	} while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
	

	return EXIT_WITH_SUCCESS;
}