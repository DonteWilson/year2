#include "Solar.h"
#include <iostream>

bool Solar::Create()
{
	float time = (float)glfwGetTime();

	if (glfwInit() == false)
			return false;

	window = glfwCreateWindow(1280, 720, "Solar Application", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{

		Gizmos::destroy();
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}



	Gizmos::create();

	mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
	mat4 sun;
	mat4 earth;
	mat4 venus;
	mat4 moon;
	mat4 jupiter;

	return true;
}
void Solar::Draw()
{
	vec4 white(1);
	vec4 black(0, 0, 0, 1);

	for (int i = 0; i < 21; ++i)
	{
		Gizmos::addLine(vec3(-10 + i, 0, 10),
			vec3(-10 + i, 0, -10),
			i == 10 ? white : black);

		Gizmos::addLine(vec3(10, 0, -10 + i),
			vec3(-10, 0, -10 + i),
			i == 10 ? white : black);
	}
	vec4 red(255, 0, 0, 1);
	vec4 blue(0, 0, 255, 1);
	vec4 orange(255, 128, 0, 1);
	vec4 brownish(233, 150, 122, 1);


	Gizmos::addSphere(vec3(sun[3]), 1, 10, 10, orange, &sun);
	Gizmos::addSphere(vec3(earth[3]), 0.75f, 10, 10, blue, &earth);
	Gizmos::addSphere(vec3(venus[3]), 0.40f, 10, 10, red, &venus);
	Gizmos::addSphere(vec3(moon[3]), 0.65f, 10, 10, white, &moon);
	Gizmos::addSphere(vec3(jupiter[3]), 0.5f, 10, 10, brownish, &jupiter);

	//Gizmos::addSphere();
	//Gizmos::addSphere();
	//Gizmos::addSphere();

	Gizmos::draw(projection * view);

	glfwSwapBuffers(window);
	glfwPollEvents();


}
bool Solar::Update()
{
	return true;

}
void Solar::Terminate()
{
	Gizmos::destroy();
	glfwDestroyWindow(window);
	
}