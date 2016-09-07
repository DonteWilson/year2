#include "Geo.h"

Geo::Geo()
{
	CreateDirectory("Shader/", NULL);
}


bool Geo::Create()
{
	//Puts the buffers onto the screen
	CreateBuffers();
	//Complies the shaders and Links them
	ComplileShader();

	return true;
}

bool Geo::CreateBuffers()
{
	Vertex vertices[4];
	unsigned int indices[4] = { 0,1,2,3 };

	vertices[0].position = vec4(-5, 0, -5, 1);
	vertices[1].position = vec4(5, 0, -5, 1);
	vertices[2].position = vec4(-5, 0, 5, 1);
	vertices[3].position = vec4(5, 0, 5, 1);

	vertices[0].colour = vec4(1, 0, 0, 1);
	vertices[1].colour = vec4(0, 1, 0, 1);
	vertices[2].colour = vec4(0, 0, 1, 1);
	vertices[3].colour = vec4(1, 1, 1, 1);

	//OPENGL DATA
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IBO);

	//Generate Array Object
	glGenVertexArrays(1, &m_VAO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ARRAY_BUFFER, 8 );


	return true;
}