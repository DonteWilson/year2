#ifndef GEO_H_
#define GEO_H_

#include <iostream>
#include "src/Gizmos.h"
#include "src/gl_core_4_4.h"
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <ext.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>
#include <fstream>
#include "Application.h"
//Geometry Tutorial
/*
1. Draw a Plane / vbo, ibo
2. Read Shaders from file
3. Draw a Cube
4. Draw a Sphere
 */

using glm::vec3;
using glm::vec4;

struct Vertex
{
	vec4 colour;
	vec4 position;
};
class Geo : public Application
{
public:
	Geo();
	void Draw() override;
	bool Update() override;
	void Terminate() override;
	bool Create() override;

private:

	GLFWwindow* window;
	glm::mat4 m_projectionViewMatrix;
	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;
	unsigned int m_IBO;
	unsigned int m_VBO;
	unsigned int m_VAO;
	unsigned int m_programID;
	float m_time;


	std::string ReadFile(const std::string &a_File);
	bool ComplileShader();
	bool Shaderfiles();
	bool CreateBuffers();

};
#endif 