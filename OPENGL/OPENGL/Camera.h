#ifndef CAMERA_H_
#define CAMERA_H_
#include <iostream>
#include <GLFW\glfw3.h>
#include <ext.hpp>
#include <glm.hpp>

using glm::mat4;
using glm::vec3;
using glm::vec4;

class Camera
{
public:
	mat4 worldTransform;
	mat4 viewTransform;
	mat4 ptojectionViewTransform;
	void setPerspective(float FoV, float aspectRatio, float near, float far);
	void setLookAt(vec3 from, vec3 to, vec3 up);
	void setPosition(vec3 position);
	virtual void update(float deltaTime) = 0;
	mat4 getWorldTransform();
	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();


private:

	mat4 projectionTransform;
	mat4 projectionViewTransform;

};

void Camera::update(float deltaTime)
{

}

void Camera::setPerspective(float FoV, float aspectRatio, float near, float far)
{
	projectionTransform = glm::perspective(FoV, aspectRatio, near, far);
}

void Camera::setLookAt(vec3 from, vec3 to, vec3 up)
{
	projectionViewTransform = glm::lookAt(from, to, up);
}

void Camera::setPosition(vec3 position)
{

}






#endif 