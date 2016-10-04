#ifndef CAMERA_H_
#define CAMERA_H_
#include <GLFW\glfw3.h>
#include <ext.hpp>
#include <glm.hpp>
#include "src/Gizmos.h"
#include "src/gl_core_4_4.h"
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>


//Enables the use of mat4, vec3, vec4
using glm::mat4;
using glm::vec3;

class Camera
{
public:
	
	mat4 viewTransform;
	mat4 ptojectionViewTransform;
	void setPerspective(float FoV, float aspectRatio, float near, float far);
	void setLookAt(vec3 from, vec3 to, vec3 up);
	void setPosition(vec3 position);
	void updateProjectionViewTransform();
	virtual void update(float deltaTime) = 0;
	mat4 getWorldTransform();
	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();


private:
	mat4 projectionTransform;
	mat4 projectionViewTransform;
	mat4 worldTransform;

};

#endif 

void Camera::updateProjectionViewTransform()
{
	//Multiplies the projectiontransform by the view transform.
	projectionViewTransform = projectionTransform * viewTransform;
}


void Camera::setPerspective(float FoV, float aspectRatio, float n, float f)
{
	//Contains perspective that holds field of view, aspectratio, near, and far
	projectionTransform = glm::perspective(FoV, aspectRatio, n, f);
}

void Camera::setLookAt(vec3 from, vec3 to, vec3 up)
{
	projectionViewTransform = glm::lookAt(from, to, up);
}

void Camera::setPosition(vec3 position)
{

}

mat4 Camera::getWorldTransform()
{
	return worldTransform;
}
mat4 Camera::getProjectionView()
{
	return projectionViewTransform;
}
mat4 Camera::getProjection()
{
	return projectionTransform;
}
mat4 Camera::getView()
{
	return viewTransform;
}







