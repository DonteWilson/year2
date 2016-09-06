#include <iostream>
#include <random>

//write a function that takes a function as a parameter.The function it receives should take two arguments(min, max).
//Calculate a random number between those two numbers and return it.If the function fails return or assert on the call. 
//if the function that takes the min, max function fails give feedback to the user.
int(*point)(const int &min, const int &max);

void F1()
{
	int num;
	num = (rand() % 10) + 1;
	std::cout << num << std::endl;
}
void F2()
{
	
}
int main()
{
	F1();

	system("pause");
	return 0;
}