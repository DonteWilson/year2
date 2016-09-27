#ifndef TEXTURES_H_
#define TEXTURES_H_

#include <iostream>
#include "src/Gizmos.h"
#include "src/gl_core_4_4.h"
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <ext.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>
#include <vector>
#include <fstream>
#include "Application.h"
#include "Camera.h"

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
	vec4 position;
	vec4 colour;

};
class Textures : public Application
{
public:
	Textures();
	void Draw() override;
	bool update() override;
	void Terminate() override;
	bool create() override;

	

private:
	Camera* myCamera;
	GLFWwindow* window;
	glm::mat4 m_projectionViewMatrix;
	unsigned int m_projectionViewUniform;
	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;
	unsigned int m_vao, m_vbo, m_ibo;
	unsigned int m_programID;
	unsigned int m_texture;
	unsigned int m_program;
	float m_time;
	float m_lastFrame;

	bool PlaneBuffer();
	bool GLInitWindow();
	std::string ReadFile(const std::string &a_File);
	Vertex* DrawHalfCircle(const int &np, const int &radius);
	bool GetShaders();
	bool Shaderfiles();
	bool CreateBuffers();

};
#endif 
