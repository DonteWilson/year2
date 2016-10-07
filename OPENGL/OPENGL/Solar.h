#ifndef _SOLAR_H_
#define _SOLAR_H_



#include "Headers/Application.h"
#include "Headers/Camera.h"
#include <GLFW/glfw3.h>

using glm::vec3;
using glm::vec4;
using glm::mat4;

class Solar : public Application
{

public:
	Solar();
	bool create() override;
	void Terminate() override;
	void Draw() override;
	bool update() override;

private:
	Camera* myCamera;
	float m_time;
	unsigned int m_programID;
	glm::mat4 m_projectionViewMatrix;
	mat4 sun;
	mat4 earth;
	mat4 venus;
	mat4 moon;
	mat4 jupiter;
	mat4 view;
	mat4 projection;
	GLFWwindow* window;

	bool GLInitWindow();



};





#endif
