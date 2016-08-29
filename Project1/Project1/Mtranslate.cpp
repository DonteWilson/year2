#include <iostream>

//Function that will translate the matrix.
void MatrixT(float vec[], int msize)
{
	float** matrix;
	matrix = new float*[msize];
	for (int i = 0; i < msize; i++)
		matrix[i] = new float[msize];

	
}

int main()
{
	//int that will hold the number that the users input.
	int num;
	//Reads out to the users.
	std::cout << "Size of Matrix?: " << std::endl;
	std::cin >> num;


	//creates a new instant of a float
	float* trans = new float[num];



	system("pause");
	return 0;
}