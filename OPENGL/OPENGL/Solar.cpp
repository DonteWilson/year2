#include "Solar.h"
#include <iostream>



Solar::Solar()
{

}

bool Solar::create()
{
	white = vec4(1);
	black = vec4(0, 0, 0, 1);
	yellow = vec4(1, 1, 0, 1);
	blue = vec4(0, 0, 1, 1);
	brownish = vec4(255, 255, 255, 1);

	if (glfwInit() == false)
	{
		return false;
	}

	window = glfwCreateWindow(1280, 720, "Solar", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return false;
	}

	Gizmos::create();
	view = glm::lookAt(glm::vec3(8, 8, 8), vec3(0), vec3(0, 1, 0));
	projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST); //enables the depth buffer

	return true;
}

bool Solar::update()
{
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Gizmos::clear();
		Gizmos::addTransform(mat4(1));

		angle += (3.14f / 180.f);

		
		glm::mat4 sunRotation = glm::rotate(angle, vec3(0, 1, 0));
		sun = glm::mat4(1) * sunRotation;

		glm::mat4 nEarth = glm::translate(translate1) * glm::rotate(angle, vec3(0, 1, 0));
		glm::mat4 nMoon = glm::translate(translate2) * glm::rotate(angle, vec3(0, 1, 0));
		earth = sun * nEarth;
		moon = earth * nMoon; 
		jupiter = nMoon * earth;

		return true;
	}
	return false;
}

void Solar::Draw()
{
	//draws the sun, earth, and the moon
	Gizmos::addSphere(vec3(sun[3]), 1, 50, 50, yellow, &sun);
	Gizmos::addSphere(vec3(earth[3]), 0.6f, 50, 50, blue, &earth);
	Gizmos::addSphere(vec3(moon[3]), 0.2f, 50, 50, white, &moon);
	Gizmos::addSphere(vec3(jupiter[3]), 0.5f, 10, 10, brownish, &jupiter);

	//draws grid
	for (int i = 0; i < 21; ++i)
	{
		Gizmos::addLine(glm::vec3(-10 + i, 0, 10), glm::vec3(-10 + i, 0, -10), i == 10 ? white : black);
		Gizmos::addLine(glm::vec3(10, 0, -10 + i), glm::vec3(-10, 0, -10 + i), i == 10 ? white : black);
	}

	Gizmos::draw(projection * view);
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Solar::Terminate()
{
	glfwDestroyWindow(window);
	Gizmos::destroy();
	glfwTerminate();
}