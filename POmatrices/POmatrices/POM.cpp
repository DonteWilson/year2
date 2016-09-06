#include <iostream>

void PerspM(float fov, float aRatio, float near, float far);
void OrthoM(float top, float bot, float left, float right, float near, float far);

void PerspM(float fov, float aRatio, float near, float far)
{
	int persp[4][4];
	float rads = (fov * 3.14) / 180;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			persp[x][y] = (x == y) ? 1 : 0;
		}
	}

	persp[3][2] = -1;
	persp[3][3] = 0;

	persp[0][0] = aRatio * 1 / tan(fov / 2);
	persp[1][1] = 1 / tan(fov / 2);
	persp[2][2] = -(far + near / far - near);
	persp[2][3] = -(2 * far * near / far - near);

	for (int x = 0; x < 4; x++)
	{
		std::cout << ",";
		for (int y = 0; y < 4; y++)
		{
			std::cout << persp[x][y] << ",";
			if (y == 3)
				std::cout << "\n";
		}
	}

	std::cout << std::endl;
}

void OrthoM(float top, float bot, float left, float right, float near, float far)
{
	int ortho[4][4];

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			ortho[x][y] = (x == y) ? 1 : 0;
		}
	}

	ortho[0][0] = 2 / right - left;
	ortho[1][1] = 2 / top - bot;
	ortho[2][2] = -2 / far - near;

	ortho[0][3] = -(right + left / right - left);
	ortho[1][3] = -(top + bot / top - bot);
	ortho[2][3] = -(far + near / far - near);

	for (int x = 0; x < 4; x++)
	{
		std::cout << ",";
		for (int y = 0; y < 4; y++)
		{
			std::cout << ortho[x][y] << ",";
			if (y == 3)
				std::cout << "\n";
		}
	}

}

int main()
{

	PerspM(1.f, (float)1090 / 720, 1.f, 1.f);
	OrthoM(0.f, 720.f, 1080.f, 0.0f, 1.f, 1.f);

	int input;
	std::cin >> input;


	system("pause");
	return 0;

}