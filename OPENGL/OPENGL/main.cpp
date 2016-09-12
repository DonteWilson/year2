#include <iostream>
#include "Application.h"
#include "Geo.h"


int main()
{
	//Creates a new solar instance.
	Application* geo = new Geo();
//	Application* app = new RenderingGeometry();



	//Checks to see if create bool is set to true, then run functions
	if (geo->create() == true)
	{
		//while update is true then the programw will run the draw function
		while (geo->update() == true)
			geo->Draw();
		geo->Terminate();
	}

	delete geo;


	
	return 0;
}