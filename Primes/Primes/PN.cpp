#include <iostream>
#include <vector>

#include <iostream>

//Mr.Matthew explained on board how this was suppose to be accomplished.
//1. create a function to calculate a prime number(show on paper or in comments what you think a prime number is. do not google it...)
//2. write a function that uses that function to find all prime numbers under 100.
//3. write a function that determines if a number is a multiple of another number.
//4. use your functions together to find all prime numbers below 1000. (edited)

bool isPrime(const int &);
bool isMultiple(int);

//Checks for prime numbers.
bool isPrime(const int &num)
{
	if (isMultiple(num)) {
		return false;
	}
	return true;
}
//Checks for multiples
bool isMultiple(int prime)
{
	for (int i = 2; i < prime; i++) {
		if (prime % i == 0) {
			return true;
		}
	}
	return false;
}

int main()
{
	//Checks for all Prime numbers under a hundred.
	for (int i = 0; i < 100; i++) {
		if (isPrime(i)) 
		{
			std::cout << i << ",";
		}
	}

	std::cout << std::endl;
	//Checks for all Prime numbers under a thousand
	for (int i = 0; i < 1000; i++) {
		if (isPrime(i)) 
		{
			std::cout << i << ",";
		}
	}

	system("pause");
	return 0;
}

