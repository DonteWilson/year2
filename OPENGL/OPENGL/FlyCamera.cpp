#include "Headers/FlyCamera.h"
#include <iostream>

FlyCamera::FlyCamera()
{
	Click = true;
	//Create the view matrix

	up = glm::vec3(0.0f, 1.0f, 0.0f);
	//Set matrix
	setLookAt(glm::vec3(10.f, 15.f, 10.f), glm::vec3(0.f, 0.f, 0.0f), up);
	setPerspective(glm::pi<float>() * 0.35f, 16 / 9.f, 0.1f, 1000.f);

	prevX = 0;
	prevY = 0;

}

void FlyCamera::update(float deltaTime)
{
	GLFWwindow* window = glfwGetCurrentContext();

	glm::mat4 Scale = glm::mat4(1);
	glm::mat4 Transform = glm::mat4(1);
	glm::mat4 Rotation = glm::mat4(1);



	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT))
	{
		double x = 0;
		double y = 0;

		float t = 0.0f;

		glfwGetCursorPos(window, &x, &y);

		if (Click)
		{
			prevX = x;
			prevY = y;
			Click = false;
		}

		float offsetX = prevX - x;
		float offSetY = prevY - y;

		offsetX *= 0.005f;
		offSetY *= 0.005f;

		if (offsetX < 1 || offsetX > 1)
		{
			t = offsetX;
			Rotation[0][0] = cos(t);
			Rotation[0][2] = sin(t);
			Rotation[2][0] = -1.f * sin(t);
			Rotation[2][2] = cos(t);
		}

		if (offSetY < 1 || offSetY > 1)
		{
			t = offSetY;
			Rotation[1][1] = cos(t);
			Rotation[1][2] = -1.f * sin(t);
			Rotation[2][1] = sin(t);
			Rotation[2][2] = cos(t);
		}

		prevX = x;
		prevY = y;
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Transform = glm::translate(vec3(0, 0, (-0.10f * deltaTime) * 10));
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Transform = glm::translate(vec3((-0.10f * deltaTime) * 10, 0, 0));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Transform = glm::translate(vec3(0, 0, (0.10f * deltaTime) * 10));
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Transform = glm::translate(vec3((0.10f * deltaTime) * 10, 0, 0));
	}

	viewTransform *= glm::inverse(Transform * Rotation * Scale);
	updateProjectionViewTransform();
}
void FlyCamera::setSpeed(float speed)
{

}

