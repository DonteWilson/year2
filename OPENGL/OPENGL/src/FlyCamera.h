#ifndef FlyCamera_H_
#define FlyCamera_H_

#include "Camera.h"

class FlyCamera : public Camera
{
public:
	virtual void update(float deltaTime) override;
	void setSpeed(float speed);


private:
	float speed;
	vec3 up;

};

#endif FlyCamera_H_