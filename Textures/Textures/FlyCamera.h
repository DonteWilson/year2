#ifndef FlyCamera_H_
#define FlyCamera_H_
#include "Camera.h"


class FlyCamera : public Camera
{
public:
	FlyCamera();
	void update(float deltaTime);
	void setSpeed(float speed);



private:
	bool Click;
	double prevX;
	double prevY;
	float speed;
	glm::vec3 up;

};


#endif FlyCamera_H_


