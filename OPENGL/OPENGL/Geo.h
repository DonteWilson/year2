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
#include <vector>
#include <fstream>
#include "Headers/Application.h"
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
class Geo : public Application
{
public:
	Geo();
	void Draw() override;
	bool update() override;
	void Terminate() override;
	bool create() override;

private:

	GLFWwindow* window;
	glm::mat4 m_projectionViewMatrix;
	unsigned int m_projectionViewUniform;
	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;
	unsigned int m_sphereVBO, m_sphereIBO, m_sphereVAO;
	unsigned int m_circleVBO, m_circleIBO, m_circleVAO;
	unsigned int m_planeVBO, m_planeIBO, m_planeVAO;
	unsigned int m_cubeVBO, m_cubeIBO, m_cubeVAO;
	unsigned int m_programID;
	float m_time;

	bool PlaneBuffer(const int &width, const int &height);
	bool SphereBuffer(const int& radius, const int & np, const int & nMeridians);
	bool CubeBuffer(const int &width, const int &height);
	bool CircleBuffer(const int &radius, bool isFilled);
	




	std::string ReadFile(const std::string &a_File);
	Vertex* DrawHalfCircle(const int &np, const int &radius);
	bool GetShaders();
	//bool Shaderfiles();
	bool CreateBuffers();

};
#endif 