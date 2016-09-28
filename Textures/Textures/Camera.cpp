#include "Camera.h"

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


