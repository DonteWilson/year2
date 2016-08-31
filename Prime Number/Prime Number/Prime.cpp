#include <iostream>
int n = 0;
void Prime()
{
	for (int j = 0; j <= 100; ++j)
	{
		int i = 2;
		for (; i <= j - 1; i++)
		{
			if (j%i == 0)
				break;
		}
		if (i == j && i != 2)
			std::cout << j << std::endl;
	}
}

void Multiples()
{
	std::cout << "\nEnter a number" << std::endl;
	std::cin >> n;

	bool multiple = true;
	for ()
	{


		if (n % 2 == 0)
		{
			multiple = true;
			break;
		}
	}
}
int main()
{  
	Prime();
	
	///FailAttempt
	//for (int i=2; i<100; i++)
	//{   //Sets prime boolean to true
	//	bool prime = true;
	//	for (int j=2; j*j<=1; j++)
	//	{
	//		
	//		if(i % j == 0)
	//		{
	//			//Sets prime to false if funciton is true
	//			prime = false;
	//			//breaks the loop
	//			break;
	//		}
	//	}
	//	//prints out every whole number after 1
	//	if (prime) std::cout << i << " ";
	//}
	system("pause");
	return 0;
}