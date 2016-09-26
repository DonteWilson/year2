#include <iostream>
#include "Application.h"
#include "textures.h"


int main()
{
	//Creates a texture instance
	Application* textures = new Textures();
	//	Application* app = new RenderingGeometry();

	//Checks to see if create bool is set to true, then run functions
	if (textures->create() == true)
	{
		//while update is true then the programw will run the draw function
		while (textures->update() == true)
			textures->Draw();
		textures->Terminate();
	}

	delete textures;



	return 0;
}
