#ifndef TEXTURES_H_
#define TEXTURES_H_

#include <iostream>
#include "Application.h"
#include "FlyCamera.h"


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
	float x, y, z, w;
	float nx, ny, nz, nw;
	float tx, ty, tz, tw;
	float s, t;
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
	unsigned int m_texture, m_normalmap;
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
