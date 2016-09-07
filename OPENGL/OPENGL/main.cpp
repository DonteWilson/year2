#include <iostream>
#include "src\gl_core_4_4.h"
#include <GLFW\glfw3.h>
#include "src\Gizmos.h"
#include <ext.hpp>
#include <glm.hpp>
#include "Solar.h"


int main()
{
	//Creates a new solar instance.
	Application* solar = new Solar();
//	Application* app = new RenderingGeometry();



	//Checks to see if create bool is set to true, then run functions
	if (solar->Create() == true)
	{
		//while update is true then the programw will run the draw function
		while (solar->Update() == true)
			solar->Draw();
		solar->Terminate();
	}

	delete solar;


	
	return 0;
}