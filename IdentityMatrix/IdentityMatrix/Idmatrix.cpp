#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>  // for setw, setfill



int binary(int number);
std::string binStr(unsigned int exponent, unsigned int size);

typedef std::vector<std::vector<int>> VectorMat;

int main()
{

	VectorMat matrix;
	//Ask the user for the size of the matrix
	std::cout << "Size of the Matrix" << std::endl;
	int input;
	std::cin >> input;

	// Initialize the matrix based on the input of the user.
	matrix.resize(input);
	for (int i = 0; i<input; i++)
		matrix[i].resize(input);

	// Fill the matrix
	for (int col = 0; col<input; col++)
	{
		std::string bin = binStr(input - col, input);
		for (int row = 0; row<input; row++)
			matrix[col][row] = bin[row] - '0';
	}


	//Display the matrix onto the screen, so its viewable to the user. Returns the value
	for (unsigned int y = 0; y < input; y++)
	{
		for (unsigned int x = 0; x < input; x++)
			std::cout << "\t" << matrix[y][x];
		std::cout << "\n";
	}
	system("pause");
	return 0;
}

std::string binStr(unsigned int exponent, unsigned int size)
{
	//Returns
	std::string str(size, '0');
	if (exponent <= size && exponent > 0)
		str[size - exponent] = '1';
	return str;


	
}

