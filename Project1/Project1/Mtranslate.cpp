#include <iostream>

void MatrixT(float vec[], int msize)
{
	float** matrix;
	matrix = new float*[msize];
	for (int i = 0; i < msize; i++)
		matrix[i] = new float[msize];

	
}

int main()
{
	int num;
	std::cout << "Size of Matrix?: " << std::endl;
	std::cin >> num;

	float* trans = new float[num];



	system("pause");
	return 0;
}