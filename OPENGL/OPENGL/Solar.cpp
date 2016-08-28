#include "Solar.h"
#include <iostream>

//sets a bool for create and if true then the function will run.
bool Solar::Create()
{
	float time = (float)glfwGetTime();

	if (glfwInit() == false)
			return false;

	//Sets window size to 1280x720 resolution
	window = glfwCreateWindow(1280, 720, "Solar Application", nullptr, nullptr);

	//If window nullptr then return the terminate to false.
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


	//Creates mat 4 objects that will be used to represent the planets.
	Gizmos::create();

	mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
	mat4 sun;
	mat4 earth;
	mat4 venus;
	mat4 moon;
	mat4 jupiter;

	//returns true
	return true;
}
//Draws visuals to the screen. 
void Solar::Draw()
{   //Sets the colors white and black
	vec4 white(1);
	vec4 black(0, 0, 0, 1);

	for (int i = 0; i < 21; ++i)
	{  //Creates lines to represent a 10x10 grid
		Gizmos::addLine(vec3(-10 + i, 0, 10),
			vec3(-10 + i, 0, -10),
			i == 10 ? white : black);

		Gizmos::addLine(vec3(10, 0, -10 + i),
			vec3(-10, 0, -10 + i),
			i == 10 ? white : black);
	}
	//Uses vec4 to create color values that will be used for the planets.
	vec4 red(255, 0, 0, 1);
	vec4 blue(0, 0, 255, 1);
	vec4 orange(255, 128, 0, 1);
	vec4 brownish(233, 150, 122, 1);

	//Adds Spheres that will represent planets
	Gizmos::addSphere(vec3(sun[3]), 1, 10, 10, orange, &sun);
	Gizmos::addSphere(vec3(earth[3]), 0.75f, 10, 10, blue, &earth);
	Gizmos::addSphere(vec3(venus[3]), 0.40f, 10, 10, red, &venus);
	Gizmos::addSphere(vec3(moon[3]), 0.65f, 10, 10, white, &moon);
	Gizmos::addSphere(vec3(jupiter[3]), 0.5f, 10, 10, brownish, &jupiter);

	//Gizmos::addSphere();
	//Gizmos::addSphere();
	//Gizmos::addSphere();

	//draws in the resolution on the screen
	Gizmos::draw(projection * view);

	glfwSwapBuffers(window);
	glfwPollEvents();


}
bool Solar::Update()
{
	//Sets float to 0
	float angle = 0;

	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//sets angle to equal pie divided by  180
		angle += (3.14f / 180.f);
		//Rotates planets around the sun uses vec3 math. 
		sun = glm::rotate(angle, vec3(0, 1, 0));
		jupiter = sun * glm::translate(vec3(9, 0, 3));
		earth = sun * glm::translate(vec3(5, 0, 1));
		venus = sun * glm::translate(vec3(7, 0, 2));
		moon = earth * glm::translate(vec3(5, 0, 0));

		Gizmos::clear();

		//Adds Gizmos transform
		Gizmos::addTransform(glm::mat4(1));

		//returns true
		return true;
	}
	return false;

}
//Terminate fucntion that will be used to destroy gizmos window.
void Solar::Terminate()
{
	Gizmos::destroy();
	glfwDestroyWindow(window);
	
}

//bool Solar::Init()
//{
//
//}