#ifndef PG_H
#define PG_H
#include<iostream>
#include "src/Gizmos.h"
#include "src/gl_core_4_4.h"
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>
#include <gtc/matrix_transform.hpp>
#include <fstream>
#include <vector>
#include "Application.h"
#include "FlyCamera.h"

using glm::vec2;
using glm::vec3;
using glm::vec4;

struct Vertex
{
	vec4 position;
	vec2 UV;

};

class PG : public Application
{
public:
	PG();
	bool create() override;
	bool update() override;
	void Draw() override;
	void Terminate() override;

private:
	Camera* myCamera;
	GLFWwindow* window;

	float m_time;
	float m_lastFrame;
	float* Perlin(const int &dims);

	glm::mat4 m_projectionViewMatrix;

	unsigned int m_texture;
	unsigned int m_grass;
	unsigned int m_rocks;
	unsigned int m_gravel;

	int m_indexCount;
	unsigned int m_programID;
	unsigned int m_planeVBO, m_planeIBO, m_planeVAO;
	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;
	unsigned int m_projectionViewUniform;

	bool PlaneBuffers(const int &width, const int &height);
	bool GLInitWindow();
	
	bool ShaderFiles();
	std::string ReadFile(const std::string &a_File);
	bool CreateShaders();

	void DrawPlane();
	
};
#endif

