#pragma once
#include "src\Gizmos.h"
#include "src\gl_core_4_4.h"
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtx\transform.hpp>



class Application
{
public:

	virtual void Draw() = 0;
	virtual bool update() = 0;
	virtual void Terminate() = 0;
	virtual bool create() = 0;


};
 

