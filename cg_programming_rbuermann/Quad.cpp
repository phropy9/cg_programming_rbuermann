#include "Quad.h"


Quad::Quad (GLuint ID, vec3 position, vec3 scaleVector) {
	this->ID = ID;
	this->position = position;
	this->scaleVector = scaleVector;
}

mat4 RenderVertex(GLuint vertexBuffer, const vec3& position, vec3 scaleVector) {
    glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glVertexAttribPointer(
		0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0
		);

	mat4 positionMatrix = translate(mat4(1.0f), position);
	mat4 scaleMatrix = scale(positionMatrix, scaleVector);

	return scaleMatrix;
}
GLuint& LoadQuad() {
		GLfloat g_vertex_buffer_data[] = {
	    0.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	for( int i = 0, size = 18; i < size; ++i) {
		g_vertex_buffer_data[i] -= 0.5f;
	}

	GLuint vertexBuffer = 0;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	return vertexBuffer;
}

mat4 RenderQuad(GLuint vertexBuffer, const vec3& position, vec3 scaleVector) {
	mat4 positionMatrix = RenderVertex(vertexBuffer, position, scaleVector);

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	return positionMatrix;
}

void Quad::Draw(mat4 projectionMatrix, mat4 viewMatrix, GLuint MVPMatrixID) {
	this->MVPMatrix = projectionMatrix * viewMatrix * RenderQuad(this->ID, this->position, this->scaleVector);
	glUniformMatrix4fv(MVPMatrixID, 1, GL_FALSE, &this->MVPMatrix[0][0]);

}


GLuint LoadBMP(const char * imagepath) {
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;
	// Open the file
	FILE * file = fopen(imagepath,"rb");
	if (!file) {
		printf("Image could not be opened\n"); return 0;
	}
	if ( fread(header, 1, 54, file)!=54 ) { 
		// If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}
	if ( header[0]!='B' || header[1]!='M' ){
		printf("Not a correct BMP file\n");
		return 0;
	}
	// Read ints from the byte array
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);
	// Some BMP files are misformatted, guess missing information
	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54; // The BMP header is done that way
	// Create a buffer
	data = new unsigned char [imageSize];
	 
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
	 
	//Everything is in memory now, the file can be closed
	fclose(file);
}

//GLuint& LoadTriangle() {
//	static const GLfloat g_vertex_buffer_data[] = {
//		-1.0f, -1.0f, 0.0f,
//		1.0f, -1.0f, 0.0f,
//		0.0f, 1.0f, 0.0f
//	};
//
//	GLuint vertexBuffer = 0;
//	glGenBuffers(1, &vertexBuffer);
//	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//
//	return vertexBuffer;
//}
//
//void RenderTriangle(GLuint vertexBuffer) {
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
//
//	glVertexAttribPointer(
//		0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0
//		);
//
//	glDrawArrays(GL_TRIANGLES, 0, 3);
//	glDisableVertexAttribArray(0);
//}