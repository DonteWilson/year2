#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtx\transform.hpp>

//Cameras and Projections tutorial

using glm::vec3;
using glm::vec4;
using glm::mat4;

class Camera
{
	mat4 worldTransform;
	mat4 viewTransform;
	mat4 projectionTransform;
	mat4 ptojectionViewTransform;

	mat4 getWorldTransform();

	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();


};

class FlyCamera: public Camera
{
	float speed;
	vec3 up;

};