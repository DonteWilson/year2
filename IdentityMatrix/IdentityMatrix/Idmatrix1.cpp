#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

int binary(int num);
std::string bStr(unsigned int expo, unsigned int size);

void Identity()
{
	std::vector<std::vector<int> > matrix;
	int input;
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
}

int main()
{
	Identity();
	std::cout << "Size of the Matrix" << std::endl;
	int input;
	std::cin >> input;

	system("pause");
	return 0;
}