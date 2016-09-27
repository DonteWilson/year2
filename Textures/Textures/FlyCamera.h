#ifndef FlyCamera_H_
#define FlyCamera_H_
#include <iostream>


class FlyCamera : public Camera
{
public:
	FlyCamera();
	void update(float deltaTime);
	void setSpeed(float speed);



private:
	bool Click;
	double prevX;
	double prevY;
	float speed;
	vec3 up;

};
FlyCamera::FlyCamera()
{
	Click = true;
	setLookAt(vec3(10.f, 10.f, 10.f), vec3(0.f, 0.f, -1.0f), up);
	setPerspective(glm::pi<float>() * 0.35f, 16 / 9.f, 0.1f, 1000.f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	prevX = 0;
	prevY = 0;
}

#endif FlyCamera_H_


void FlyCamera::update(float deltaTime)
{
	GLFWwindow* window = glfwGetCurrentContext();

	mat4 Scale = mat4(1);
	mat4 Transform = mat4(1);
	mat4 Rotation = mat4(1);

	

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

		offsetX += 0.005f;
		offSetY += 0.005f;

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
		Transform = glm::translate(vec3(0, 0, (-0.10f * deltaTime) * 10));
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



