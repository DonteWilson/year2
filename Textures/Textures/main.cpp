#include <iostream>
#include "Application.h"
//#include "textures.h"
#include "PG.h"


int main()
{
	//Creates a texture instance
	Application* pg = new PG();
	//	Application* app = new RenderingGeometry();

	//Checks to see if create bool is set to true, then run functions
	if (pg->create() == true)
	{
		//while update is true then the programw will run the draw function
		while (pg->update() == true)
			pg->Draw();
		pg->Terminate();
	}

	delete pg;



	return 0;
}
