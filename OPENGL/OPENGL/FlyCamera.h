#ifndef FlyCamera_H_
#define FlyCamera_H_

#include "Camera.h"

class FlyCamera : public Camera
{
public:
	virtual void update(float deltaTime) override;
	void setSpeed(float speed);


private:
	float speed;
	vec3 up;

};


void FlyCamera::update(float deltaTime)
{
	GLFWwindow* window = glfwGetCurrentContext();

	mat4 Scale = mat4(1);
	mat4 Transform = mat4(1);
	mat4 Rotation = mat4(1);

	if(glfwGetMouseButton(window, GLFW_KEY_DOWN))
	{
		
	}

	if(glfwGetKey(window, GLFW_KEY_W))
	{
		Transform = glm::translate(vec3(0, 0, (0 * deltaTime) * 10));
	}
	if(glfwGetKey(window,GLFW_KEY_A))
	{
		Transform = glm::translate(vec3(0, 0, (0.10f * deltaTime) * 10));
	}
	if(glfwGetKey(window,GLFW_KEY_S))
	{
		Transform = glm::translate(vec3(0, 0, (0.10f * deltaTime) * 10));
	}
	if(glfwGetKey(window,GLFW_KEY_D))
	{
		Transform = glm::translate(vec3(0, 0, (0.10f * deltaTime) * 10));
	}
}
void FlyCamera::setSpeed(float speed)
{
	
}


#endif FlyCamera_H_
