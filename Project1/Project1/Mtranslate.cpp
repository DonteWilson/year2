#include <iostream>

int** IdMatrix(int row, int height);
void Multi(int** identity);

//Void function for multiplying by the identity
void Multi(int** identity)
{
	
	std::cout << "\nAssigned Matrix: [5,3,2,1] \n";
	std::cout << "\nMultiplied by the Matrix Returns \n";

	//Created new matrix based on what was given in morning assignment. [5,3,2,1]
	int newMatrix[4] = { 5,3,2,1 };
	int transM[4][1];
	//Math for multiplying the identity by the [5,3,2,1] matrix
	transM[0][0] = identity[0][0] * newMatrix[0] + identity[0][1] * newMatrix[1] + identity[0][2] * newMatrix[2] + identity[0][3] * newMatrix[3];
	transM[1][0] = identity[1][0] * newMatrix[0] + identity[1][1] * newMatrix[1] + identity[1][2] * newMatrix[2] + identity[1][3] * newMatrix[3];
	transM[2][0] = identity[2][0] * newMatrix[0] + identity[2][1] * newMatrix[1] + identity[2][2] * newMatrix[2] + identity[2][3] * newMatrix[3];
	transM[3][0] = identity[3][0] * newMatrix[0] + identity[3][1] *	newMatrix[1] + identity[3][2] * newMatrix[2] + identity[3][3] * newMatrix[3];

	std::cout << "[";
	//Gets the results and puts it in brackets
	for (int i = 0; i < 4; i++)
	{
		std::cout << *transM[i] << " ";
	}

	std::cout << "]";
}

//Forms the identity matrix
int** IdMatrix(int rows, int cols)
{
	int** IdM = 0;

	IdM = new int*[rows];

	for (int x = 0; x < rows; x++)
	{
		IdM[x] = new int[cols];

		for (int y = 0; y < cols; y++)
		{
			IdM[x][y] = (x == y) ? 1 : 0;
		}
	}

	double offset = sqrt(rows * cols) - 1;

	std::cout << "Morning Assignment Translation\n";
	std::cout << "Identity Matrix:\n";
	for (int x = 0; x < rows; x++)
	{
		//std::cout << "\n";
		for (int y = 0; y < cols; y++)
		{
			std::cout << IdM[x][y];
			if (y == offset)
				std::cout << "\n";
		}
	}

	return IdM;
}



int main()
{
	//Sets the identity to even rows and columns
	int rows = 4;
	int cols = 4;

	int** identityMatrix = IdMatrix(rows, cols);

	//Runs the multiplication function on the 
	Multi(identityMatrix);

	int matrix;
	std::cin >> matrix;

	return 0;

}

