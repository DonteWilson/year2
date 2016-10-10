#ifndef _SOLAR_H_
#define _SOLAR_H_



#include "Headers/Application.h"
#include <GLFW/glfw3.h>

using glm::vec3;
using glm::vec4;
using glm::mat4;

//solar system class. everything is public. inherits from app class.
class Solar : public Application
{
public:
	Solar();
	float angle = 0.0f;
	bool create() override;
	bool update() override;
	void Draw() override;
	void Terminate() override;

	GLFWwindow* window;
	vec4 white, black, yellow, blue, brownish;
	mat4 view, projection;
	mat4 sun, earth, moon, jupiter = mat4(1); 
	vec3 translate1 = glm::vec3(4, 0, 0);       
	vec3 translate2 = glm::vec3(2, 0, 0);       
	       
};





#endif
