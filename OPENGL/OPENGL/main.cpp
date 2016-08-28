#include <iostream>
#include "src\gl_core_4_4.h"
#include <GLFW\glfw3.h>
#include "src\Gizmos.h"
#include <ext.hpp>
#include <glm.hpp>

#include "Solar.h"


//using glm::vec3;
//using glm::vec4;
//using glm::mat4;




int main()
{
	Solar* solar = new Solar;

	if (solar->Create() == true)
	{
		while (solar->Update() == true)
			solar->Draw();
		solar->Terminate();
	}

	delete solar;

	//Application * app = new Solar();
	//while (app->Init())
	//{

	//}

	//if (glfwInit() == false)
	//	return -1;

	//GLFWwindow* window = glfwCreateWindow(1280, 720,
	//	"Computer Graphics",
	//	nullptr, nullptr);

	//if (window == nullptr)
	//{
	//	glfwTerminate();
	//	return -2;
	//}

	//glfwMakeContextCurrent(window);

	//if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	//{
	//
	//	Gizmos::destroy();
	//	glfwDestroyWindow(window);
	//	glfwTerminate();
	//	return -3;
	//}

	//

	//Gizmos::create();

	//mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	//mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
	//mat4 sun;
	//mat4 earth;
	//mat4 venus;
	//mat4 moon;
	//mat4 jupiter;


	//auto major = ogl_GetMajorVersion();
	//auto minor = ogl_GetMinorVersion();
	//printf("GL: %i.%i\n", major, minor);

	//glClearColor(0.25f, 0.25f, 0.25f, 1);
	//glEnable(GL_DEPTH_TEST);
	//float angle = 0;

	//while (glfwWindowShouldClose(window) == false &&	glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	//{
	//	float time = (float)glfwGetTime();

	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	angle += (3.14f/180.f);
	//	
	//	sun = glm::rotate(angle, vec3(0, 1, 0));
	//	jupiter = sun * glm::translate(vec3( 9, 0, 3));
	//	earth = sun * glm::translate(vec3(5, 0, 1));
	//	venus = sun * glm::translate(vec3(7, 0, 2));
	//	moon = earth * glm::translate(vec3(5, 0, 0));

	//	Gizmos::clear();

	//	Gizmos::addTransform(glm::mat4(1));

	//	vec4 white(1);
	//	vec4 black(0, 0, 0, 1);

	//	for (int i = 0; i < 21; ++i)
	//	{
	//		Gizmos::addLine(vec3(-10 + i, 0, 10),
	//			vec3(-10 + i, 0, -10),
	//			i == 10 ? white : black);

	//		Gizmos::addLine(vec3(10, 0, -10 + i),
	//			vec3(-10, 0, -10 + i),
	//			i == 10 ? white : black);
	//	}
	//	vec4 red(255, 0, 0, 1);
	//	vec4 blue(0, 0, 255, 1);
	//	vec4 orange(255, 128,0,1 );
	//	vec4 brownish(233, 150, 122, 1);
	//	

	//	Gizmos::addSphere(vec3(sun[3]), 1, 10, 10, orange, &sun);
	//	Gizmos::addSphere(vec3(earth[3]), 0.75f, 10, 10, blue, &earth);
	//	Gizmos::addSphere(vec3(venus[3]), 0.40f, 10, 10, red, &venus);
	//	Gizmos::addSphere(vec3(moon[3]), 0.65f, 10, 10, white, &moon);
	//	Gizmos::addSphere(vec3(jupiter[3]), 0.5f, 10, 10, brownish, &jupiter);

	//	//Gizmos::addSphere();
	//	//Gizmos::addSphere();
	//	//Gizmos::addSphere();

	//	Gizmos::draw(projection * view);

	//	glfwSwapBuffers(window);
	//	glfwPollEvents();
	//}

	
	return 0;
}