#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>  
//Shows the Idenity Matrix


int binary(int num);
std::string bStr(unsigned int expo, unsigned int size);

int main()
{

	std::vector<std::vector<int> > matrix;
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
		std::string b = bStr(input - col, input);
		for (int row = 0; row<input; row++)
			matrix[col][row] = b[row] - '0';
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

std::string bStr(unsigned int expo, unsigned int size)
{
	//Returns
	std::string str(size, '0');
	if (expo <= size && expo > 0)
		str[size - expo] = '1';
	return str;


	
}

