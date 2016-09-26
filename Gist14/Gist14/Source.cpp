#include<iostream>
#include <assert.h>
//Write a function that tests if a point falls within a specified distance(“dist”) of any part of a solid, 
//2D rectangle.The rectangle is specified by the bottom left corner, a width, and a height.

struct Point
{
	float x;
	float y;
};
struct Rectangle
{
	Point bottomLeft;
	float width;
	float height;
};

bool IsPointWithinDistofRectangle(const Rectangle& rect, const Point& point, float dist)
{
	//Checking to see if the point is on the rectangle. Looks over the x and the y.
	if (point.x <= rect.bottomLeft.x + rect.width && point.x >= rect.bottomLeft.x) 
	{
		if (point.y <= rect.bottomLeft.y + rect.height && point.y >= rect.bottomLeft.y) 
		{
			return true;
		}
	}

	//Checking to see if point is within distance of the rectangle. Looks over the x and the y
	else if (point.x <= (rect.bottomLeft.x + rect.width + dist) && point.x >= rect.bottomLeft.x - dist) 
	{
		if (point.y <= rect.bottomLeft.y + rect.height + dist && point.y >= rect.bottomLeft.y - dist) 
		{
			return true;
		}
	}

	//If not on rectangle and not within distance, return 0 for false.
	else 
    {
		return false;
	}
}
int main()
{
	//Not sure where to start from here.
	system("pause");
	return 0;
}