#ifndef _SOLAR_H_
#define _SOLAR_H_



#include "Application.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;

class Solar : public Application
{

public:

	bool Create();
	void Terminate();
	void Draw();
	bool Update();

private:

	mat4 sun;
	mat4 earth;
	mat4 venus;
	mat4 moon;
	mat4 jupiter;
	mat4 view;
	mat4 projection;
	GLFWwindow* window;



};





#endif
