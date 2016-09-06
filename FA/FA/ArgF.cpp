#include <iostream>

int n1 = 300;
int n2 = 125;
int n3 = 1234;
int value = 0;

//Stores and array of functions
void FuncArray(void(*function)(), void(*array[3])())
{
	for (int i = 0; i < 3; i++)
	{
		if (array[i] == 0)
		{
			array[i] = function;
			break;
		}
	}
}

void(*storage[3])() = { 0, 0, 0 };
void Func1()
{
	value = n1 * n2;
	std::cout << value << std::endl;
}
void Func2()
{
	value = n3 / n2;
	std::cout << value << std::endl;

}
void Func3()
{
	std::cout << "This is my multiple functions gist" << std::endl;
}

int main()
{
	FuncArray(Func1, storage);
	FuncArray(Func2, storage);
	FuncArray(Func3, storage);

	for (int i = 0; i < 3; i++)
	{
		(*storage[i])();
	}


	system("pause");
	return 0;
}