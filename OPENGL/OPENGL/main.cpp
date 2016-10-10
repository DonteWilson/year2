#include <iostream>
#include "Headers/Application.h"
//#include "Geo.h"
#include "Solar.h"


int main()
{
	//Creates a new solar instance.
	Application* solar = new Solar();
//	Application* app = new RenderingGeometry();



	//Checks to see if create bool is set to true, then run functions
	if (solar->create() == true)
	{
		//while update is true then the programw will run the draw function
		while (solar->update() == true)
			solar->Draw();
		solar->Terminate();
	}

	delete solar;


	
	return 0;
}