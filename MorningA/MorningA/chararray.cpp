#include <iostream>
#include <string>

//write a function that calculates the length of a character array using only pointers.pass that function as an argument to another function to evaluate it's correctness.
bool Check(int )
{
	return true;
}

int Size(const char* c)
{
	int count = 0;
	for(int i = 0; i <= c[i]; i++)
	{
		count++;
	}
	//Displays Character array size.
	std::cout << "Character Array Size: " << count + 1 << "\n";
	return count + 1;
}

int main()
{
	/*char * test = new char[100];
	std::cout << "Input String: ";
	std::string str;
	getline(std::cin, str);

	for(int i = 0; i<str.length(); i++)
	{
		test[i] = str[i];
	}

	int length = str.length();

	test[length] = '\0';

	std::cout << test << '\n';
*/
	char append[] = { "Jittery" };
	Size(append), 9;
	system("pause");
	return 0;
}
