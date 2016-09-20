#include <iostream>

//Gist 12: write a function that multiplies two numbers.You can only use addition or subtraction and you can only check whether a number is positive negative or 0. Can not use > >= < <=
//Return and parameters are unsigned integers

int n1;
int n2;
int answer;

int main()
{ 
	answer = 0;
	//Asks the user what numbers he wants to multiply/
	std::cout << "Give the two numbers you want to multiply" << std::endl;
	std::cin >> n1;
	std::cin >> n2;

	for (int i = 0; i  n2; i++)
		answer = answer + n1;
	
	//prints out answer
	std::cout << answer << std::endl;
	system("pause");
	return 0;

}